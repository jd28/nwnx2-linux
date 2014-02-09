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

#ifndef NWNX_PATCH_H
#define NWNX_PATCH_H

#include "NWNXLib.h"
#include "NWNXBase.h"

extern int (*CNWSCreature__ResolveAttackNext)(CNWSCreature *, uint32_t, int32_t, int32_t);
extern int (*CNWSCreatureStats__GetEffectImmunityNext)(CNWSCreatureStats *, uint8_t, CNWSCreature *);
extern int (*CNWSEffectListHandler__OnApplyAbilityDecreaseNext)(CNWSEffectListHandler *, CNWSObject *, CGameEffect *, int32_t);
extern int (*CNWSEffectListHandler__OnApplyCurseNext)(CNWSEffectListHandler *, CNWSObject *, CGameEffect *, int32_t);
extern int (*CNWSCreatureStats__GetWeaponFocusNext)(CNWSCreatureStats *, CNWSItem *);

// Hooks
void Hook_ResolveAttack(CNWSCreature *, uint32_t, int32_t, int32_t);
int Hook_GetEffectImmunity(CNWSCreatureStats *, uint8_t, CNWSCreature *);
int Hook_OnApplyAbilityDecrease(CNWSEffectListHandler *, CNWSObject *, CGameEffect *, int32_t);
int Hook_OnApplyCurse(CNWSEffectListHandler *, CNWSObject *, CGameEffect *, int32_t);
int Hook_GetWeaponFocus(CNWSCreatureStats *, CNWSItem *);

class CNWNXPatch : public CNWNXBase {
public:
    CNWNXPatch();
    virtual ~ CNWNXPatch();

    bool OnCreate (gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest (char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject (char *gameObject, char *Request);
    
    const char* GetConf(const char* key);
    void HookFunctions();
    void InitFunctionPointers();
    void RemoveCopyItemAndModifyColorCap();

    int override_immunity;
};

#endif /* NWNX_PATCH_H */
