/***************************************************************************
    NWN Extender - Hook Demandres function in the server
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

#if !defined(HookDemandRes_h_)
#define HookDemandRes_h_

//#include <string.h>
//#include <stdio.h>
#include "NwnDefines.h"
#include "../../api/all.h"

int HookFunctions();

unsigned long FindHookRetrieveResEntry();
int RetrieveResEntry(CExoResMan * pthis, char* resRef, NwnResType resType, void ** v1, void** v2);

//void DemandResHookProc();
unsigned long FindHookDemandRes();
void* DemandRes(CExoResMan * pthis, CRes* cRes);

#endif
