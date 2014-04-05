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

#include "NWNXCombat.h"

extern CNWNXCombat combat;

int32_t Hook_GetTotalEffectBonus(CNWSCreature *cre, uint8_t eff_switch , CNWSObject *versus, int elemental,
                                 int32_t is_crit, uint8_t save, uint8_t save_vs, uint8_t skill,
                                 uint8_t ability, int32_t is_offhand) {
    
    int32_t result = 0;
    auto c = combat.get_creature(cre->obj.obj_id);
    if ( !c ) { return result; }

    if ( eff_switch == 3 ) { // Saving Throw
        result = c->defense.getSaveEffectBonus(save, save_vs);
    }
    else if ( eff_switch == 4 ) { // Ability Score
        result = c->getAbilityEffectModifier(ability);
    }
    else if ( eff_switch == 5 ) { // Skill Rank
        result = c->getSkillEffectModifier(skill);
    }    
    else {
        result = CNWSCreature__GetTotalEffectBonus(cre, eff_switch, versus, elemental, is_crit, save, save_vs, skill, ability, is_offhand);
    }
    return result;
}
