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

#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

void Hook_InitializeNumberOfAttacks(CNWSCombatRound *combat_round) {
    CNWSCreature* cre = combat_round->cr_original;

    if(!nl_pushfunction(L, "NWNXSolstice_InitializeNumberOfAttacks")) {
        return;
    }

    lua_pushinteger(L, cre->obj.obj_id);

    if (lua_pcall(L, 1, 0, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_InitializeNumberOfAttacks : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return;
    }
}
