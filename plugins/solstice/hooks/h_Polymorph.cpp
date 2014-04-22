/***************************************************************************
    Copyright (C) 2011-2014 jmd (jmd2028 at gmail dot com)

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

int32_t Hook_Polymorph(CNWSCreature *cre, int32_t polyid, CGameEffect *eff, int32_t a) {
    if ( cre->cre_is_poly ) { return 0; }
    solstice.poly_eff = eff;

    if(!nl_pushfunction(L, "NWNXSolstice_Polymorph"))
        return 0;

    lua_pushinteger(L, cre->obj.obj_id);
    lua_pushinteger(L, polyid);
    lua_pushinteger(L, a);

    if (lua_pcall(L, 3, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_Polymorph : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return 0;
    }

    int32_t res = lua_tointeger(L, -1);
    lua_pop(L, 1);
    solstice.poly_eff = nullptr;
    return res;
}
