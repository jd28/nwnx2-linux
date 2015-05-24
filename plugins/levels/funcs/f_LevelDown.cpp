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

#include "NWNXLevels.h"

void Func_LevelDown(CGameObject *ob, char *value) {
    CNWSCreature *cre;
    CNWSCreatureStats *info;
    int i, drop, level = 0;

    if ( ob == NULL                                    || 
         (cre = ob->vtable->AsNWSCreature(ob)) == NULL ||
         cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    info = cre->cre_stats;

    sscanf(value, "%d", &drop);

    for( i = 0; i < info->cs_classes_len; i++ ){
        level += info->cs_classes[i].cl_level;
    }  

    if( drop >= level ) {
        drop = level - 1;
    }
    else if ( drop < 1 ){
        snprintf(value, strlen(value), "%d", -1);
        return;
    }

    for( ; drop > 0; drop--, level-- ) {
        CNWSCreatureStats__LevelDown(info, nwn_GetLevelStats(info, level)); 
    }

    snprintf(value, strlen(value), "%d", 1);
}
