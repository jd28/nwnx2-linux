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

#ifndef _NX_NWN_STRUCT_CNWCLASS_
#define _NX_NWN_STRUCT_CNWCLASS_

struct CNWClass_s {
    uint32_t     cl_name_tlk;                    /* 0x0000 */
    uint32_t     cl_name_lower_tlk;              /* 0x0004 */
    uint32_t     cl_name_plural;                 /* 0x0008 */
    uint32_t     cl_description_tlk;             /* 0x000C */
    CExoString   cl_icon;                        /* 0x0010-14 */
    CExoString  *cl_prereq_table;                /* 0x0018 */
    uint8_t      field_1C;
    uint8_t      field_1D;
    uint8_t      field_1E;
    uint8_t      cl_attack_bonus[60];            /* 0x001F */
    uint8_t      cl_hit_dice;                    /* 0x005C */
    uint8_t      cl_skill_points;                /* 0x005D */
    uint8_t      cl_save_fort[60];               /* 0x005E-98 */
    uint8_t      cl_save_will[60];               /* 0x0099-D4 */
    uint8_t      cl_save_reflex[60];             /* 0x00D5-111 */
    uint8_t      field_112;                      /* 0x0112 */
    uint8_t      field_113;
    uint8_t    **cl_spellknown_table;            /* 0x0114 */
    uint8_t      cl_num_spell_levels[40];        /* 0x0118 */
    uint8_t     *cl_spellgain_table[40];         /* 0x0140 */
    uint16_t    *cl_skills_table;                /* 0x01E0 */
    uint16_t     cl_skills_table_len;            /* 0x01E4 */
    uint16_t     field_01E6;                     /* 0x01E6 */
    uint16_t    *cl_feats;                       /* 0x01E8 */
    uint8_t      cl_feats_len;                   /* 0x01EC */
    uint8_t      cl_bonus_feats[40];             /* 0x01ED */
    uint8_t      field_0215;                     /* 0x0215 */
    uint8_t      cl_primary_ability;             /* 0x0216 */
    uint8_t      cl_str_adjust;                  /* 0x0217 */
    uint8_t      cl_dex_adjust;                  /* 0x0218 */
    uint8_t      cl_con_adjust;                  /* 0x0219 */
    uint8_t      cl_int_adjust;                  /* 0x021A */
    uint8_t      cl_wis_adjust;                  /* 0x021B */
    uint8_t      cl_cha_adjust;                  /* 0x021C */
    uint8_t      cl_align_restrict;              /* 0x021D */
    uint8_t      cl_align_restrict_type;         /* 0x021E */
    uint8_t      field_21F;                      /* 0x021F */
    uint32_t     cl_invert_restrict;             /* 0x0220 */
    uint8_t      cl_eff_cr_level[40];            /* 0x0224*/
    uint32_t     field_24C;                      /* */
    uint32_t     cl_player_class;                /* 0x0250 */
    uint32_t     cl_spell_caster;                /* 0x0254 */ 
    uint32_t     cl_max_level;                   /* 0x0258 */
    uint32_t     cl_xp_penalty;                  /* 0x025C */
    uint32_t     cl_package;                     /* 0x0260 */
    uint8_t      cl_arcane_splvl_mod;            /* 0x0264 */
    uint8_t      cl_divine_splvl_mod;            /* 0x0265 */
    uint8_t      cl_epic_level;                  /* 0x0266 */
    uint8_t      field_267;                      /* 0x0267 */
  
};

#endif // _NX_NWN_STRUCT_CNWCLASS_
