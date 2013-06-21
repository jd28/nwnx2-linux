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

#ifndef _NX_NWN_STRUCT_CNWFEAT_
#define _NX_NWN_STRUCT_CNWFEAT_

struct CNWFeat_s {
    uint32_t                    feat_name_strref;               /* 00 */
    uint32_t                    feat_desc_strref;               /* 04 */
    uint32_t                    feat_category;                  /* 08 */
    uint32_t                    feat_max_cr;                    /* 0C */
    CResRef                     feat_icon;                      /* 10 */
    uint32_t                    feat_gain_multiple;             /* 20 */
    uint32_t                    feat_all_class_use;             /* 24 */
    uint32_t                    feat_target_self;               /* 28 */
    uint32_t                    feat_hostile;                   /* 2C */
    uint8_t                     feat_min_ab;                    /* 30 */
    uint8_t                     feat_min_str;                   /* 31 */
    uint8_t                     feat_min_dex;                   /* 32 */
    uint8_t                     feat_min_int;                   /* 33 */
    uint8_t                     feat_min_wis;                   /* 34 */
    uint8_t                     feat_min_con;                   /* 35 */
    uint8_t                     feat_min_cha;                   /* 36 */
    uint8_t                     feat_min_spell_lvl;             /* 37 */
    uint16_t                    feat_req_feat_1;                /* 38 */
    uint16_t                    feat_req_feat_2;                /* 3A */
    uint16_t                    feat_req_or[5];                 /* 3C */
    uint16_t                    feat_req_skill_1;               /* 46 */
    uint16_t                    feat_req_skillranks_1;          /* 48 */
    uint16_t                    feat_req_skill_2;               /* 4A */
    uint16_t                    feat_req_skillranks_2;          /* 4C */
    uint16_t                    field_004E;                     /* 4E */
    uint32_t                    field_0050;                     /* 50 */
    uint8_t                     feat_master;                    /* 54 */
    uint8_t                     feat_min_level;                 /* 54 */
    uint8_t                     feat_max_level;                 /* 54 */
    uint8_t                     feat_min_level_class;           /* 54 */
    uint32_t                    field_0058;                     /* 58 */
    uint32_t                    feat_spell_id;                  /* 5C */
    uint8_t                     feat_uses;                      /* 60 */
    uint8_t                     field_0061;                     /* 61 */
    uint8_t                     field_0062;                     /* 62 */
    uint8_t                     field_0063;                     /* 63 */
    uint32_t                    field_0064;                     /* 64 */
    uint32_t                    field_0068;                     /* 68 */
    uint32_t                    feat_req_action;                /* 6C */
};

#endif /* _NX_NWN_STRUCT_CNWFEAT_ */

/* vim: set sw=4: */
