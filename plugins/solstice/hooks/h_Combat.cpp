/***************************************************************************
    Copyright (C) 2011-2012 jmd (jmd2028 at gmail dot com)

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

extern CNWNXSolstice solstice;
extern lua_State *L;

// CNWSCombatRound::InitializeNumberOfAttacks()
void Hook_InitializeNumberOfAttacks(CNWSCombatRound *cr) {
    if(!nl_pushfunction(L, "NWNXSolstice_InitializeNumberOfAttacks"))
        return;

    // Push object ID.
    lua_pushinteger(L, cr->cr_original->obj.obj_id);

    if (lua_pcall(L, 1, 0, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_InitializeNumberOfAttacks : %s\n", lua_tostring(L, -1));
        return;
    }
}

//-- CNWSCreatureStats::GetWeaponFinesse(CNWSItem *)
int32_t Hook_GetWeaponFinesse(CNWSCreatureStats *stats, CNWSItem *item) {
    if(!nl_pushfunction(L, "NWNXSolstice_GetWeaponFinesse"))
        return 0;

    // Push object ID.
    lua_pushinteger(L, stats->cs_original->obj.obj_id);
    lua_pushinteger(L, item ? item->obj.obj_id : OBJECT_INVALID);

    if (lua_pcall(L, 2, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_GetWeaponFinesse : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int32_t result = lua_toboolean(L, -1);
    lua_pop(L, 1);
    return result;

}


//-- CNWSCreatureStats::GetCriticalHitMultiplier(int)
int32_t Hook_GetCriticalHitMultiplier(CNWSCreatureStats *stats, int32_t is_offhand) {
    if(!nl_pushfunction(L, "NWNXSolstice_GetCriticalHitMultiplier"))
        return 0;

    // Push object ID.
    lua_pushinteger(L, stats->cs_original->obj.obj_id);
    lua_pushboolean(L, is_offhand);

    if (lua_pcall(L, 2, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_GetCriticalHitMultiplier : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int32_t result = lua_tointeger(L, -1);
    lua_pop(L, 1);
    return result;
}

// CNWSCreatureStats::GetCriticalHitRoll(int)
int32_t Hook_GetCriticalHitRoll(CNWSCreatureStats *stats, int32_t is_offhand) {
    if(!nl_pushfunction(L, "NWNXSolstice_GetCriticalHitRoll"))
        return 0;

    // Push object ID.
    lua_pushinteger(L, stats->cs_original->obj.obj_id);
    lua_pushboolean(L, is_offhand);

    if (lua_pcall(L, 2, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_GetCriticalHitRoll : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int32_t result = lua_tointeger(L, -1);
    lua_pop(L, 1);
    return result;
}

/*
int32_t Hook_GetArmorClassVersus(stats, vs, touch)
   touch = touch == 1
   local cre = GetObjectByID(stats.cs_original.obj.obj_id)
   return cre:GetACVersus(OBJECT_INVALID, touch)
end

Hook.hook {
   address = 0x0814088C,
   func = Hook_GetArmorClassVersus,
   type = "int32_t (*)(CNWSCreatureStats *, CNWSCreature *, int32_t)",
   flags = Hook.HOOK_DIRECT,
   length = 5
}

-- CNWSCreatureStats::GetAttackModifierVersus(CNWSCreature *)
int32_t Hook_GetAttackModifierVersus(stats, cre)
   local cre = GetObjectByID(stats.cs_original.obj.obj_id)
   return cre:GetAttackBonusVs(OBJECT_INVALID)
end

Hook.hook {
   address = 0x081445B4,
   func = Hook_GetAttackModifierVersus,
   type = "int32_t (*)(CNWSCreatureStats *, CNWSCreature *)",
   flags = Hook.HOOK_DIRECT,
   length = 5
}
*/

// CNWSCreature::ResolveDamageShields(CNWSCreature *)
int32_t Hook_ResolveDamageShields(CNWSCreature *cre, CNWSCreature *attacker) {
    if (!cre || !attacker) return 0;
    if(!nl_pushfunction(L, "NWNXSolstice_ResolveDamageShields"))
        return 0;

    // Push object ID.
    lua_pushinteger(L, cre->obj.obj_id);
    lua_pushinteger(L, attacker->obj.obj_id);

    if (lua_pcall(L, 2, 0, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_ResolveDamageShields : %s\n", lua_tostring(L, -1));
        return 0;
    }
    return 0;
}
