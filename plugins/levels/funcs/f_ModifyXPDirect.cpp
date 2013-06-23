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

#include "NWNXLevels.h"
#include "talib/util/math.h"

void Func_ModifyXPDirect(CGameObject *ob, char *value) {
    CNWSCreature *cre = nwn_GetCreatureByID(ob->id);
    int32_t adj = 0;
    if ( !cre ||
         sscanf(value, "%d", &adj) != 1 ) {
        snprintf(value, strlen(value), "%d", -1);
        return;
    }
    if ( adj > 0 ) {
        cre->cre_stats->cs_xp += adj;
    }
    else {
        uint32_t n = -adj;
        if ( n >= cre->cre_stats->cs_xp ) {
            cre->cre_stats->cs_xp = 1;
        }
        else {
            cre->cre_stats->cs_xp -= n;
        }
    }

    cre->cre_stats->cs_xp = CLAMP<uint32_t>(cre->cre_stats->cs_xp,
                                            1, 100000000);
    
    snprintf(value, strlen(value), "%d", cre->cre_stats->cs_xp);
}
