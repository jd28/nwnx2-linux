/***************************************************************************
    Copyright (C) 2011-2012 jmd ( jmd2028 at gmail dot com )

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

#include "NWNXSolstice.h"

#define HOOK(orig, addr, hook, bytes) \
    *(void**)&orig = nx_hook_function((void*)addr, (void*)hook, bytes, NX_HOOK_DIRECT | NX_HOOK_RETCODE)
    

bool hook_functions(){
    HOOK(CVirtualMachine__RunScript, 0x08261F94, Hook_RunScriptStart, 5);
    HOOK(CVirtualMachine__RunScriptSituation, 0x08262534, Hook_RunScriptSituationStart, 5);
    nx_hook_function((void *)0x0815479c,
                     (void *)Hook_GetFeatTotalUses, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)0x08153E00,
                     (void *)Hook_GetFeatRemainingUses, 5, NX_HOOK_DIRECT);

    nx_hook_function((void *)0x080F982C,
                     (void *)Hook_SetCombatMode, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)0x0812BCB4,
                     (void *)Hook_ToggleMode, 7, NX_HOOK_DIRECT);


/*

#ifdef NS_PROFILE_SCRIPTS
    nx_hook_function((void *)0x0826252C,
                     (void *)Hook_RunScriptEnd, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)0x08262763,
                     (void *)Hook_RunScriptSituationEnd, 5, NX_HOOK_DIRECT);
#endif
*/
    return true;
}
