/*
 *  NWNeXalt - Empty File
 *  (c) 2007 Doug Swarin (zac@intertex.net)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 *  $HeadURL$
 *
 */

#ifndef _NX_NWN_STRUCT_CCOMBATINFORMATION_
#define _NX_NWN_STRUCT_CCOMBATINFORMATION_

struct CCombatInformation_s {
    uint8_t           ci_num_attacks;
    uint8_t           ci_onhand_attack_mod;
    uint8_t           ci_onhand_damage_mod;
    uint8_t           ci_offhand_attack_mod;
    uint8_t           ci_offhand_damage_mod;
    uint8_t           ci_spell_resistance;
    uint8_t           ci_arcane_spell_failure;
    uint8_t           ci_armor_check_penalty;
    uint8_t           ci_unarmed_damage_dice;
    uint8_t           ci_unarmed_damage_die;
    uint8_t           field_0A;  // Creature attack dice...
    uint8_t           field_0B;
    uint8_t           field_0C;
    uint8_t           field_0D;
    uint8_t           field_0E;
    uint8_t           field_0F;
    uint8_t           field_10;
    uint8_t           field_11;
    uint8_t           field_12;
    uint8_t           ci_onhand_crit_range;
    uint8_t           ci_onhand_crit_mult;
    uint8_t           field_15;
    uint8_t           field_16;
    uint8_t           field_17;
    uint8_t           ci_offhand_weapon_equipped;
    uint8_t           field_19;
    uint8_t           field_1A;
    uint8_t           field_1B;
    uint8_t           ci_offhand_crit_range;
    uint8_t           ci_offhand_crit_mult;
    uint8_t           field_1E;
    uint8_t           field_1F;
    CExoArrayList_ptr ci_atk_mod_list; // CCombatInformationNode
    CExoArrayList_ptr ci_dmg_mod_list; // CCombatInformationNode
    nwn_objid_t       ci_right_equip;
    nwn_objid_t       ci_left_equip;
    CExoString        ci_right_string;
    CExoString        ci_left_string;
    uint8_t           ci_damage_dice;
    uint8_t           ci_damage_die;
    uint8_t           field_52;
    uint8_t           field_53;
    uint8_t           field_54;
};

#endif /* _NX_NWN_STRUCT_CCOMBATINFORMATION_ */

/* vim: set sw=4: */
