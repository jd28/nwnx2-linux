
/***************************************************************************
    ExaltReplace.c - Implementation of NWN combat replacement functions
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

int Hook_GetWeaponFinesse (CNWSCreatureStats *info, CNWSItem *weapon) {
    if(!nl_pushfunction(L, "NWNXSolstice_GetWeaponFinesse"))
        return 0;

    // Push object ID.
    lua_pushinteger(L, info->cs_original->obj.obj_id);
    lua_pushinteger(L, weapon ? weapon->obj.obj_id : OBJECT_INVALID);

    if (lua_pcall(L, 2, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_GetWeaponFinesse : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int32_t res = lua_tointeger(L, -1);
    lua_pop(L,1);

    solstice.Log(3, "GetWeaponFinesse: obj: %X, result: %d\n", info->cs_original->obj.obj_id, res);

    return res;
}


/* vim: set sw=4: */
