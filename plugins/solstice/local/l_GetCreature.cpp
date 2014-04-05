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

Creature *Local_GetCreature(uint32_t id) {
    CNWSCreature *cre = nwn_GetCreatureByID(id);
    if ( !cre ) return NULL;

    auto it = solstice.cache.find(id);
    if ( it == solstice.cache.end() ) {
        solstice.Log(3, "Creature ID: %X.  Not found, attempting insert.\n", id);
        auto c = solstice.cache.insert( {id, Creature(cre)} );
        return &c.first->second;
    }
    else if ( !cre ) {
        solstice.Log(3, "Creature does not exist removing: %X.\n", id);
        return NULL;
    }

    return &it->second;
}
