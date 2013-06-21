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

#ifndef _NX_NWN_STRUCT_CNWSCOMBATROUND_
#define _NX_NWN_STRUCT_CNWSCOMBATROUND_

struct CNWSCombatRound_s {
    CNWSCombatAttackData          cr_attack_data[50];           /* 0x0000 - 0x20CC*/
    CExoArrayList_uint16          cr_special_attack;            /* 20D0 */
    CExoArrayList_uint16          cr_special_attack_id;         /* 20D8 */
    int16_t                       cr_attack_id_1;
    int16_t                       cr_attack_id_2;
    uint8_t                       cr_round_started;             /* 0x20EC */
    uint8_t                       field_30;
    uint8_t                       field_31;
    uint8_t                       field_32;
    uint8_t                       cr_spellcast_round;           /* 0x20f0 */
    uint8_t                       field_34;
    uint8_t                       field_35;
    uint8_t                       field_36;
    uint32_t                      cr_timer;
    uint32_t                      cr_round_length;
    uint32_t                      cr_overlap_amount;
    uint32_t                      cr_bleed_timer;               /* 0x2100 */
    uint8_t                       cr_round_paused;
    uint8_t                       field_54;
    uint8_t                       field_55;
    uint8_t                       field_56;
    uint32_t                      cr_round_pauser;
    uint32_t                      cr_pause_timer;
    uint8_t                       cr_infinite_pause;
    uint8_t                       field_66;
    uint8_t                       field_67;
    uint8_t                       field_68;
    uint8_t                       cr_current_attack;             /* 0x2114 */
    uint8_t                       cr_attack_group;
    uint8_t                       field_71;
    uint8_t                       field_72;
    uint8_t                       cr_deflect_arrow;              /* 0x2118 */
    uint8_t                       field_74;
    uint8_t                       field_75;
    uint8_t                       field_76;
    uint8_t                       cr_weapon_ineffective;         /* 0x211c */
    uint8_t                       field_78;
    uint8_t                       field_79;
    uint8_t                       field_80;
    uint8_t                       cr_epic_dodge_used;             /* 0x2120 */
    uint8_t                       field_82;
    uint8_t                       field_83;
    uint8_t                       field_84;
    uint32_t                      cr_parry_index;                /* 0x2124 */
    uint32_t                      cr_num_AOOs;                   /* 0x2128 */
    uint32_t                      cr_num_cleaves;                /* 0x212C */
    uint32_t                      cr_num_circle_kicks;           /* 0x2130 */
    uint32_t                      cr_new_target;
    uint32_t                      cr_onhand_atks;                /* 0x2138 */
    uint32_t                      cr_offhand_atks;               /* 0x213C */
    uint32_t                      cr_offhand_taken;              /* 0x2140 */
    uint32_t                      cr_extra_taken;                /* 0x2144 */
    uint32_t                      cr_additional_atks;            /* 0x2148 */
    uint32_t                      cr_effect_atks;                /* 0x214C */
    uint8_t                       cr_parry_actions;              /* 0x2150 */
    uint8_t                       field_130;                     /* 0x2151 */
    uint8_t                       field_131;                     /* 0x2152 */
    uint8_t                       field_132;                     /* 0x2153 */
    uint32_t                      cr_dodge_target;               /* 0x2154 */ 
    uint32_t                    **cr_sched_action_lst;           /* 0x2158 */
    CNWSCreature                 *cr_original;                   /* 0x215C */   
};

#endif /* _NX_NWN_STRUCT_CNWSCOMBATROUND_ */

/* vim: set sw=4: */
