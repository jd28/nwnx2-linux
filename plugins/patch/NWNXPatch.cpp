/***************************************************************************
    Copyright (C) 2011-2013 jmd (jmd2028 at gmail dot com)

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

#include "NWNXPatch.h"

#define HOOK(orig, addr, hook, bytes)                                   \
    do { *(void**)&orig = nx_hook_function((void*)addr, (void*)hook, bytes, NX_HOOK_DIRECT | NX_HOOK_RETCODE); \
         Log(0, "Hooked %s at %x\n", #hook, (addr)); } while (0)
    
#define REPLACE(addr, hook, bytes)                                     \
    do { nx_hook_function((void*)addr, (void*)hook, bytes, NX_HOOK_DIRECT); \
         Log(0, "Hooked %s at %x\n", #hook, (addr)); } while(0)

#define SET(nm, addr)                           \
    if ( nm == NULL ) *(int*)& nm = addr

int (*CNWSCreature__ResolveAttackNext)(CNWSCreature *, uint32_t, int32_t, int32_t) = NULL;
int (*CNWSCreatureStats__GetEffectImmunityNext)(CNWSCreatureStats *, uint8_t, CNWSCreature *) = NULL;
int (*CNWSEffectListHandler__OnApplyAbilityDecreaseNext)(CNWSEffectListHandler *, CNWSObject *, CGameEffect *, int32_t) = NULL;
int (*CNWSEffectListHandler__OnApplyCurseNext)(CNWSEffectListHandler *, CNWSObject *, CGameEffect *, int32_t) = NULL;
int (*CNWSCreatureStats__GetWeaponFocusNext)(CNWSCreatureStats *, CNWSItem *) = NULL;

CNWNXPatch::CNWNXPatch() {
    confKey = strdup("PATCH");
}

const char* CNWNXPatch::GetConf(const char* key) {
    return (*nwnxConfig)[confKey][key].c_str();
}

CNWNXPatch::~CNWNXPatch() {}

char *CNWNXPatch::OnRequest (char *gameObject, char *Request, char *Parameters) {
    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);
    Log(1, "\nReturn: \"%s\"\n", Parameters);

    return NULL;
}

unsigned long CNWNXPatch::OnRequestObject (char *gameObject, char *Request) {
    unsigned long ret = OBJECT_INVALID;

    Log(1, "ObjReq: \"%s\"\n", Request);
    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXPatch::OnCreate (gline *config, const char *LogDir) {
    char log[128];
    
    // Function Pointers

    sprintf(log, "%s/nwnx_patch.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // write copy information to the log file
    Log (0, "NWNX Patch version 0.1 for Linux.\n");
    Log (0, "(c) 2013 by jmd (jmd2028 at gmail dot com) aka leo_x\n");

    if ( atoi(GetConf("enable_item_copy_patch")) ) {
        RemoveCopyItemAndModifyColorCap();
    }
    
    InitFunctionPointers();
    HookFunctions();

    
    return true;
}

void CNWNXPatch::RemoveCopyItemAndModifyColorCap() { 
    char* p = (char*)0x0822037d;
    nx_hook_enable_write(p, 1);
    Log(0, "CopyItemAndModifyColor cap changed from %x to %x\n", *p, 0xF);
    *p = 0xF;
}

void CNWNXPatch::HookFunctions() {
    bool enable_curse_patch = atoi(GetConf("enable_curse_patch"));
    bool enable_equip_ability_patch = atoi(GetConf("enable_equip_abil_decrease"));
    
    if ( enable_curse_patch || enable_equip_ability_patch ) {
        HOOK(CNWSCreatureStats__GetEffectImmunityNext,
             0x0815FF10,
             Hook_GetEffectImmunity,
             5);

        HOOK(CNWSEffectListHandler__OnApplyAbilityDecreaseNext,
             0x0816F4D8,
             Hook_OnApplyAbilityDecrease,
             5);

        if ( enable_curse_patch ) {
            HOOK(CNWSEffectListHandler__OnApplyCurseNext,
                 0x08177DC4,
                 Hook_OnApplyCurse,
                 5);
        }

    }

    if ( atoi(GetConf("enable_weapon_focus_patch")) ) {
        HOOK(CNWSCreatureStats__GetWeaponFocusNext,
             CNWSCreatureStats__GetWeaponFocus,
             Hook_GetWeaponFocus,
             6);
    }

    if ( atoi(GetConf("enable_circle_kick_patch")) ) {
        HOOK(CNWSCreature__ResolveAttackNext,
             0x080E6C44,
             Hook_ResolveAttack,
             5);
    }

    
}

void CNWNXPatch::InitFunctionPointers() {
    SET(CNWSObject__GetDead, 0x081D1C10);
}

#undef HOOK
#undef REPLACE
#undef SET
