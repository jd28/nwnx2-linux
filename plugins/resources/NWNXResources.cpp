/***************************************************************************
    NWNXResMan.cpp - Implementation of the CNWNXResources class.
    Copyright (C) 2005 Ingmar Stieger (papillon@nwnx.org)
    copyright (c) 2006 dumbo (dumbo@nm.ru) & virusman (virusman@virusman.ru)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ***************************************************************************/

#include "NWNXResources.h"
#include "NwnDefines.h"
#include "HookDemandRes.h"
#include <stdio.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNWNXResources::CNWNXResources()
{
    confKey = "RESOURCES";
    bufferSize = 0;
    disableHook= 0;
}

CNWNXResources::~CNWNXResources()
{
}

bool CNWNXResources::OnCreate (gline *config, const char *LogDir)
{
    // call the base class function
    char log[MAXPATH];

    sprintf(log, "%s/nwnx_resources.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    LoadConfiguration();
    WriteLogHeader();
    HookFunctions();

    hDemandRes = CreateHookableEvent("NWNX/Resources/DemandResource");
    hResExists = CreateHookableEvent("NWNX/Resources/ResourceExists");


    return true;
}

char* CNWNXResources::OnRequest (char* gameObject, char* Request, char* Parameters)
{
    return NULL;
}

bool CNWNXResources::OnRelease ()
{
    Log(0, "o Shutdown.\n");
    return true;
}

void* CNWNXResources::DemandRes(CExoResMan *pResMan, CRes *cRes, const std::string& resRef, NwnResType resType)
{
    unsigned long size;

    if (resRef.empty() || resRef == "*" || resRef == "default" )
        return NULL;

    if (cRes == NULL) {
        Log(5, "o Request for internal resource = %s (type %X)\n", resRef.c_str(), resType);

        // nothing for us to do
        return NULL;
    }

    const char* resExt = NwnGetResTypeExtension(resType);
    std::string resrefWithExt = resRef + "." + resExt;


    // Insert entry, or lookup old one...
    std::pair<ResourceMap::iterator, bool> lookup = resFiles.insert(ResourceMap::value_type(resrefWithExt, CResFileInfo()));
    CResFileInfo& fileInfo = lookup.first->second;

    ResManResExistsStruct event = { resrefWithExt.c_str(), 0, false };
    NotifyEventHooks(hResExists, (WPARAM)&event, 0);

    if (event.exists)
        fileInfo.latest_mtime = event.mtime;

    Log(4, "File: %s, Exists?: %d, mtime: %d\n", resrefWithExt.c_str(), event.exists, fileInfo.latest_mtime);


    if(cRes->m_nID == 0xFFFFFFFF) {
        Log(4, "ID: -1: %s\n", resRef.c_str());
    }

    if (fileInfo.res) {
        pResMan->RemoveFromToBeFreedList(fileInfo.res); // Remove res from to be freed list so that at shutdown there are no double frees.
    }

    // If the file is a script and the latest reported time is older or equal to the
    // last returned time return a file from the cache.
    if(resType == NwnResType_NCS && fileInfo.data && fileInfo.latest_mtime <= fileInfo.mtime){
        Log(4, "Skipping %s... Data: %p\n", resrefWithExt.c_str(), fileInfo.data);
        if(resType == NwnResType_NCS){
            cRes->m_pResource = fileInfo.data;

            cRes->m_nDemands = 1;
            cRes->field_8 = 0x4;
            cRes->m_status = 2;
            cRes->m_nSize = fileInfo.size;

            if(!cRes->m_nID || cRes->m_nID == 0xFFFFFFFF)  //resource is not indexed
            {
                cRes->m_nID = 0;
            }

            if (cRes->vtbl) {
                CResNCS *pNCS = (CResNCS*) cRes;
                pNCS->m_bLoaded = 0;
            }
            int (*pServFunc) (CRes * cRes) = (int (*)(CRes * cRes))cRes->vtbl->OnResourceServiced;
            Log(4, "Calling CRes*::OnResourceServiced: %08lx\n", pServFunc);
            int nRet = pServFunc(cRes);
            Log(4, "Resulting Structure:\n");
            DumpResStruct(cRes);
        }

        fileInfo.res = cRes;
        // Either NULL or a cached file.
        return cRes->m_pResource;
    }
    else {
        ResManDemandResStruct demandResInfo = { resrefWithExt.c_str(), resType, NULL, 0, fileInfo.mtime, fileInfo.latest_mtime };
        int notifyRet = NotifyEventHooks(hDemandRes, (WPARAM)&demandResInfo, 0);
        if (!notifyRet) { return NULL; }
        if (demandResInfo.pData && demandResInfo.size) {
            // if anything is in the cache delete it.
            if (fileInfo.data) {
                free(fileInfo.data);
            }

            //Log(4, "Got data from Hook, returning (size = %d): %s\n", demandResInfo.size, demandResInfo.pData);
            pScriptBuffer = (char*) demandResInfo.pData;
            fileInfo.size = size = demandResInfo.size;
            fileInfo.mtime = demandResInfo.mtime;

            Log(4, "Loading external resouce: %s, mtime: %d\n", resrefWithExt.c_str(), fileInfo.mtime);
            Log(4, "Original Structure:\n");
            DumpResStruct(cRes);
            Log(4, "Free memory: %d\n", pResMan->TotalAvailableMemory);
            if(pResMan->TotalAvailableMemory < size){ //not enough memory
                Log(4, "Freeing some memory\n");
                while ( 1 )
                {
                    if (size <= pResMan->TotalAvailableMemory)
                        break;
                    if (!pResMan->FreeChunk())
                        break;
                }
            }

            if(cRes->m_pResource)
            {
                free(cRes->m_pResource);
                pResMan->TotalAvailableMemory += cRes->m_nSize;
            }
            else
            {
                // resource loaded
                // set resStruct

                cRes->m_nDemands = 1;
                cRes->field_8 = 0x4;
                cRes->m_status = 2;
                if(!cRes->m_nID || cRes->m_nID == 0xFFFFFFFF)  //resource is not indexed
                {
                    cRes->m_nID = 0;
                }
            }

            cRes->m_pResource = pScriptBuffer;

            // Cache NCS data in the file info struct to avoid memory leaks.
            if(resType == NwnResType_NCS){
                fileInfo.data = cRes->m_pResource;
                Log(4, "Setting Cache Data: %p\n", fileInfo.data);
                fileInfo.res = cRes;
            }

            cRes->m_nSize = size;

            pResMan->TotalAvailableMemory -= size;

            // Call server function which sets various data pointers
            if (cRes->vtbl)
            {
                if(resType == NwnResType_NCS){
                    CResNCS *pNCS = (CResNCS*) cRes;
                    pNCS->m_bLoaded = 0;
                }
                else if (resType == NwnResType_2DA) {
                    CRes2DA *t = (CRes2DA*) cRes;
                    t->m_bLoaded = 0;
                }

                int (*pServFunc) (CRes * cRes) = (int (*)(CRes * cRes))cRes->vtbl->OnResourceServiced;
                Log(4, "Calling CRes*::OnResourceServiced: %08lx\n", pServFunc);
                int nRet = pServFunc(cRes);
                Log(4, "Return value: %d\n", nRet);
            }
            Log(4, "Resulting Structure:\n");
            DumpResStruct(cRes);

            return cRes->m_pResource;

        }
    }
    return NULL;
}

void CNWNXResources::DumpResStruct(CRes *cRes)
{
    Log(4, "- m_nDemands = %d\n", cRes->m_nDemands);
    Log(4, "- m_nRequests = %d\n", cRes->m_nRequests);
    Log(4, "- m_nID = %08lX\n", cRes->m_nID);
    Log(4, "- m_pResource = %08lx\n", cRes->m_pResource);
    Log(4, "- m_nSize = %d\n", cRes->m_nSize);
    if (cRes->ResName) {
        CKeyTableEntry *key = reinterpret_cast<CKeyTableEntry*>(cRes->ResName);
        char buf[17] = {0};
        strncpy(buf, key->m_cResRef.m_resRef, 16);
        Log(4, "- m_sName = %s\n", buf);
    }
    Log(4, "- flags = %x\n", cRes->field_8);
    Log(4, "- m_status = %d\n", cRes->m_status);
    Log(4, "- m_pKeyEntry = %08lx\n", cRes->ResName);
}

int CNWNXResources::ResourceExists(const std::string& resRef, NwnResType resType) {
    const char* resExt = NwnGetResTypeExtension(resType);
    std::string resrefWithExt = resRef + "." + resExt;

    // Insert entry, or lookup old one...
    std::pair<ResourceMap::iterator, bool> lookup = resFiles.insert(ResourceMap::value_type(resrefWithExt, CResFileInfo()));
    CResFileInfo& fileInfo = lookup.first->second;

    ResManResExistsStruct event = { resrefWithExt.c_str(), 0, false };
    NotifyEventHooks(hResExists, (WPARAM)&event, 0);

    if (event.exists)
        fileInfo.latest_mtime = event.mtime;

    Log(4, "File: %s, Exists?: %d\n", resrefWithExt.c_str(), event.exists);

    return event.exists;
}

void CNWNXResources::LoadConfiguration () {
    if (nwnxConfig->exists(confKey)) {
        strncpy(m_sourcePath, (*nwnxConfig)[confKey]["SourcePath"].c_str(), MAXPATH);
    }
}

void CNWNXResources::WriteLogHeader()
{
    // write copy information to the log file
    Log(0, "NWNX Resource Manager 1.0.1 for Linux.\n");
    Log(0, "(c) 2005 by Ingmar Stieger (papillon@nwnx.org)\n");
    Log(0, "(c) 2006 by dumbo (dumbo@nm.ru)\n");
    Log(0, "(c) 2006-2010 by virusman (virusman@virusman.ru)\n");
    Log(0, "* Resource source path is: %s\n", m_sourcePath);
}
