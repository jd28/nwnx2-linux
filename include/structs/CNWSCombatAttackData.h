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

#ifndef _NX_NWN_STRUCT_CNWSCOMBATATTACKDATA_
#define _NX_NWN_STRUCT_CNWSCOMBATATTACKDATA_

struct CNWSCombatAttackData_s {
    uint8_t               cad_attack_group;        /* 0000 */
    uint8_t               field_01;                /* 0001 */
    uint16_t              cad_anim_length;         /* 0002 */
    uint32_t              cad_target;              /* 0004 */
    uint16_t              cad_react_delay;         /* 0008 */
    uint16_t              cad_react_anim;          /* 000A */
    uint16_t              cad_react_anim_len;      /* 000C */
    uint8_t               cad_attack_roll;         /* 000E */
    uint8_t               cad_threat_roll;         /* 000F */
    uint32_t              cad_attack_mod;          /* 0010 */
    uint8_t               cad_missed;              /* 0014 */
    uint8_t               field_15;                /* 0015 */
    uint16_t              cad_damage[13];          /* 0016 */
    uint8_t               cad_attack_type;         /* 0030 */
    uint8_t               cad_attack_mode;         /* 0031 */
    uint8_t               cad_concealment;         /* 0032 */
    uint8_t               field_33;                /* 0033 */
    uint32_t              cad_ranged_attack;       /* 0034 */
    uint32_t              cad_sneak_attack;        /* 0038 */
    uint32_t              cad_death_attack;        /* 003C */
    uint32_t              cad_killing_blow;        /* 0040 */
    uint32_t              cad_coupdegrace;         /* 0044 */
    uint32_t              cad_critical_hit;        /* 0048 */
    uint32_t              cad_attack_deflected;    /* 004C */
    uint8_t               cad_attack_result;       /* 0050 */
    uint8_t               field_51;                /* 0051 */
    uint16_t              cad_special_attack;      /* 0052 */
    uint16_t              field_54;                /* 0054 */
    uint16_t              field_56;                /* 0056 */
    Vector                cad_ranged_target_loc;   /* 0058-0060 */
    uint32_t              cad_ammo_id;             /* 0064 */
    CExoString            cad_debug_attack;        /* 0068 */
    CExoString            cad_debug_dmg;           /* 0070 */
    CExoArrayList_ptr     cad_onhit_effs;          /* 0078 */
    CExoArrayList_ptr     cad_onhit_spells;        /* 0084 */
    CExoArrayList_ptr     cad_onhit_spells2;       /* 0090 */
    CExoArrayList_ptr     cad_feedback;            /* 009C */
};

#endif /* _NX_NWN_STRUCT_CNWSCOMBATATTACKDATA_ */

/* vim: set sw=4: */
