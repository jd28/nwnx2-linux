/***************************************************************************
    Copyright (C) 2013 jmd (jmd2028 at gmail dot com)

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

#include "NWNXEffects.h"

int (*CServerAIMaster__OnEffectApplied_orig)(CServerAIMaster *, CNWSObject *, CGameEffect *, int32_t) = NULL;
int (*CServerAIMaster__OnEffectRemoved_orig)(CServerAIMaster *, CNWSObject *, CGameEffect *) = NULL;

#define HOOK(orig, addr, hook, bytes)                                   \
    *(void**)&orig = nx_hook_function((void*)addr, (void*)hook, bytes, NX_HOOK_DIRECT | NX_HOOK_RETCODE)

bool hook_functions() {
    HOOK(CNWSCreature__RemoveBadEffects, 0x0812DFB8,
         Hook_RemoveBadEffects, 5);

    nx_hook_function((void*)0x0817D22C,
                     (void*)Hook_OnApplyModifyNumAttacks, 5, NX_HOOK_DIRECT);

    nx_hook_function((void*)0x08177D00,
                     (void*)Hook_OnRemoveModifyNumAttacks, 5, NX_HOOK_DIRECT);


    nx_hook_function((void*)0x0820db94,
                     (void*)Hook_ExecuteCommandApplyEffectOnObject, 5, NX_HOOK_DIRECT);


    nx_hook_function((void*)0x081D65D8,
                     (void*)Hook_CExoArrayList_CGameEffect_Insert, 5, NX_HOOK_DIRECT);

    unsigned char *eff_num_ints = (unsigned char*)0x0817dd37;
    nx_hook_enable_write(eff_num_ints, 1);
    memset((void *)eff_num_ints, (uint8_t)10, 1);

    return true;
}
