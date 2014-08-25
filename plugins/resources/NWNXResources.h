/***************************************************************************
    NWNXResMan.h - Interface for the CNWNXResources class.
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

#ifndef NWNX_RESOURCES_H
#define NWNX_RESOURCES_H

#include <string>
#include <sys/stat.h>
#include <unordered_map>

#include "NWNXBase.h"
#include "NwnDefines.h"
#include "HookDemandRes.h"

#define MAXPATH 512

struct CResFileInfo
{
    CResFileInfo() : size(0), mtime(0), latest_mtime(0), data(NULL), res(NULL) {}
    off_t size;
    time_t mtime;
    time_t latest_mtime;
    void *data;
    CRes *res;
};

typedef std::unordered_map<std::string, CResFileInfo> ResourceMap;

class CNWNXResources : public CNWNXBase
{

public:
    CNWNXResources();
    virtual ~CNWNXResources();
    bool OnCreate (gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();
    void LoadConfiguration();
    void WriteLogHeader();

    void *DemandRes(CExoResMan *pResMan, CRes* cRes, const std::string& resRef, NwnResType resType);
    void DumpResStruct(CRes *cRes);
    int ResourceExists(const std::string& resRef, NwnResType resType);

private:
    bool disableHook;
    char *pScriptBuffer;
    int bufferSize;
    char m_sourcePath[MAXPATH];
    HANDLE hDemandRes;
    HANDLE hResExists;
    ResourceMap resFiles;
};

#endif // NWNX_RESOURCES_H
