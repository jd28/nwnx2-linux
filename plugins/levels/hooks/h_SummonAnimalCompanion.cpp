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
#include <algorithm>

extern CNWNXLevels levels;

void Hook_SummonAnimalCompanion(CNWSCreature *cre) {
    CResRef resref;
    std::fill_n(resref.resref, 16, 0);

    int32_t level = nwn_GetLevelByClass(cre->cre_stats, CLASS_TYPE_DRUID);
    level += nwn_GetLevelByClass(cre->cre_stats, CLASS_TYPE_RANGER);
    if ( level <= 0 ) { 
        return;
    }
    else if ( level > 40 ) {
        level = 40;
    }
    
    uint32_t assoc_id = CNWSCreature__GetAssociateId(cre, 2, 1);
    CNWSCreature *assoc = NULL;
    if ( assoc_id != OBJECT_INVALID &&
         (assoc = nwn_GetCreatureByID(assoc_id)) != NULL ) {
        CNWSCreature__ReceiveAssociateCommand(assoc, -8);
    }

    C2DA *fam2da = (*NWN_Rules)->ru_2das->tda_hen_companion;
    uint32_t type = cre->cre_stats->cs_acomp_type;
    const char *base = nwn_Get2daString(fam2da, "BASERESREF", type);
    if ( level > 9 ) {
        snprintf(resref.resref, 16, "%s%d", base, level);
    }
    else {
        snprintf(resref.resref, 16, "%s0%d", base, level);
    }

    for ( size_t i = 0; i < 16; ++i ) {
        resref.resref[i] = tolower(resref.resref[i]);
    }

    levels.Log(3, "SummonAnimalCompanion Resref: |%s|\n", resref.resref);

    char *name = new char[250];
    snprintf(name, 250, "%s", cre->cre_stats->cs_acomp_name.text);

    levels.Log(3, "SummonAnimalCompanion Name: |%s|\n", name);

    CNWSCreature__SummonAssociate(cre, resref, &name, 2);
    cre->cre_summoned_acomp = 1;
}
