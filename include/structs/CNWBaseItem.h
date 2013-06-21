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

#ifndef _NX_NWN_STRUCT_CNWBASEITEM_
#define _NX_NWN_STRUCT_CNWBASEITEM_

struct CNWBaseItem_s {
    uint32_t        bi_name_strref;                         /* 0x000 */
    uint32_t        bi_equip_slots;                         /* 0x004 */
    uint8_t         bi_weapon_wield;                        /* 0x008 */
    uint8_t         bi_damage_type;                         /* 0x009 */
    uint8_t         field_A;                                /* 0x00A */
    uint8_t         field_B;                                /* 0x00B */
    uint32_t        bi_range_min;                           /* 0x00C */
    uint32_t        bi_range_max;                           /* 0x0010 */
    uint8_t         bi_slot_width;                          /* 0x0014 */
    uint8_t         bi_slot_height;                         /* 0x0015 */
    uint8_t         bi_model_type;                          /* 0x0016 */
    uint8_t         bi_charges_starting;                    /* 0x0017 */
    uint8_t         bi_is_ranged;                           /* 0x0018 */
    uint8_t         bi_size;                                /* 0x0019 */
    uint8_t         bi_dmg_dice;                            /* 0x001A */
    uint8_t         bi_dmg_sides;                           /* 0x001B */
    uint8_t         bi_crit_range;                          /* 0x001C */
    uint8_t         bi_crit_mult;                           /* 0x001D */
    uint8_t         bi_category;                            /* 0x001E */
    uint8_t         field_1F;                               /* 0x001F */
    float           bi_base_cost;                           /* 0x0020 */
    uint8_t         bi_stacking;                            /* 0x0024 */
    uint8_t         field_25;                               /* 0x0025 */
    uint8_t         field_26;                               /* 0x0026 */
    uint8_t         field_27;                               /* 0x0027 */
    uint8_t         bi_value_multiplier;                    /* 0x0028 */
    uint8_t         field_29;                               /* 0x0029 */
    uint8_t         field_2A;                               /* 0x002A */
    uint8_t         field_2B;                               /* 0x002B */
    uint32_t        bi_desc_strref;                         /* 0x002C */
    uint8_t         bi_props_min;                           /* 0x0030 */
    uint8_t         bi_props_max;                           /* 0x0031 */
    uint8_t         bi_prob_column;                         /* 0x0032 */
    uint8_t         bi_store_panel;                         /* 0x0033 */
    uint8_t         bi_store_panel_sort;                    /* 0x0034 */
    uint8_t         bi_anim_slash_l;                        /* 0x0035 */
    uint8_t         bi_anim_slash_r;                        /* 0x0036 */
    uint8_t         bi_anim_slash_s;                        /* 0x0037 */
    uint8_t         bi_ilr_stack_size;                      /* 0x0038 */
    uint8_t         field_39;                               /* 0x0039 */
    uint8_t         field_3A;                               /* 0x003A */
    uint8_t         field_3B;                               /* 0x003B */
    float           bi_pref_atk_distance;                   /* 0x003C */
    char            bi_item_class[16];                      /* 0x0040 */
    uint32_t        bi_can_rotate_icon;                     /* 0x0050 */
    uint32_t        field_54;                               /* 0x0054 */
    char            bi_default_icon[16];                    /* 0x0058 */
    char            bi_default_model[16];                   /* 0x0068 */
    uint8_t         field_78;                               /* 0x0078 */
    uint8_t         field_79;                               /* 0x0079 */
    uint8_t         field_7A;                               /* 0x007A */
    uint8_t         field_7B;                               /* 0x007B */
    uint8_t         bi_container;                           /* 0x007C */
    uint8_t         field_7D;                               /* 0x007D */
    uint8_t         field_7E;                               /* 0x007E */
    uint8_t         field_7F;                               /* 0x007F */
    uint8_t         field_80;                               /* 0x0080 */
    uint8_t         field_81;                               /* 0x0081 */
    uint8_t         field_82;                               /* 0x0082 */
    uint8_t         field_83;                               /* 0x0083 */
    uint32_t        bi_inventory_sound_type;                /* 0x0084 */
    uint32_t       *bi_req_feats;                           /* 0x0088 */
    uint32_t        bi_req_feats_len;                       /* 0x008C */
    uint32_t        bi_basic_stat_strref;                   /* 0x0090 */
    uint32_t        bi_rotate_on_ground;                    /* 0x0094 */
    uint32_t        bi_ten_times_lbs;                       /* 0x0098 */
    uint8_t         bi_ac_base;                             /* 0x009C */
    uint8_t         bi_ac_type;                             /* 0x009D */
    uint8_t         bi_weapon_sound;                        /* 0x009E */
    int8_t          bi_armor_check_penaly;                  /* 0x009F */
    uint8_t         bi_ammunition_type;                     /* 0x00A0 */
    uint8_t         bi_qb_behavior;                         /* 0x00A1 */
    uint8_t         bi_arcane_spell_fail;                   /* 0x00A2 */
    uint8_t         field_A3;                               /* 0x00A3 */
};
#endif /* _NX_NWN_STRUCT_CNWBASEITEM_ */

