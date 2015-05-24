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

uint8_t Hook_GetSpellsKnownPerLevel(CNWClass *cls, uint8_t level, int8_t sp_level, int8_t cls_type, uint16_t race, uint8_t cha){

    if(level > 39)
        level = 39;
    
    if(sp_level < cls->cl_num_spell_levels[level]
       && cls->cl_spellknown_table
       && (cls_type != 1
           || cls->cl_spellknown_table[level][sp_level-1]
           || (*NWN_Rules)->ru_races[race].ra_cha_adjust + cha > sp_level + 10)) {
        return cls->cl_spellknown_table[level][sp_level];
    }

    return 0;

}
