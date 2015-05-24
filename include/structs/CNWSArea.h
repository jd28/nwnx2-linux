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

#ifndef _NX_NWN_STRUCT_CNWSAREA_
#define _NX_NWN_STRUCT_CNWSAREA_

struct CNWSArea_s {
    uint32_t                    area_type;
    uint32_t                    field_04;
    uint32_t                    field_08;
    uint32_t                    field_0C;
    uint32_t                    field_10;
    uint32_t                    field_14;
    uint32_t                    field_18;
    uint32_t                    field_1C;
    uint32_t                    field_20;
    uint32_t                    field_24;
    uint32_t                    field_28;
    uint32_t                    field_2C;
    uint32_t                    field_30;
    uint32_t                    field_34;
    uint32_t                    field_38;
    uint32_t                    field_3C;
    uint32_t                    field_40;
    uint32_t                    field_44;
    uint32_t                    field_48;
    uint32_t                    field_4C;
    uint32_t                    field_50;
    uint32_t                    field_54;
    uint32_t                    field_58;
    uint32_t                    field_5C;
    uint32_t                    field_60;
    uint32_t                    field_64;
    uint32_t                    area_moonfog_color;
    uint8_t                     area_moonfog_amount;
    uint8_t                     field_6D;
    uint8_t                     field_6E;
    uint8_t                     field_6F;
    uint32_t                    field_70;
    uint32_t                    field_74;
    uint32_t                    field_78;
    uint32_t                    area_sunfog_color;
    uint8_t                     area_sunfog_amount;
    uint8_t                     field_81;
    uint8_t                     field_82;
    uint8_t                     field_83;
    uint32_t                    field_84;
    uint32_t                    area_use_daynight_cycle;
    uint32_t                    field_8C;
    uint8_t                     area_skybox;
    uint8_t                     field_91;
    uint8_t                     field_92;
    uint8_t                     field_93;
    uint32_t                    field_94;
    uint32_t                    area_no_rest;
    uint8_t                     area_shadow_opacity;
    uint8_t                     field_9D;
    uint8_t                     field_9E;
    uint8_t                     field_9F;
    float                       area_fogclip_distance;
    uint32_t                    field_A4;
    uint32_t                    field_A8;
    uint32_t                    field_AC;
    uint32_t                    field_B0;
    uint32_t                    field_B4;
    uint32_t                    field_B8;
    uint32_t                    field_BC;
    uint32_t                    field_C0;
    uint32_t                    field_C4;
    uint32_t                    area_obj_id;
    uint32_t                    field_CC;
    uint32_t                    field_D0;
    uint32_t                    area_num_players;
    uint32_t                    field_D8;
    uint32_t                    field_DC;
    uint32_t                    field_E0;
    uint32_t                    field_E4;
    uint32_t                    field_E8;
    uint32_t                    field_EC;
    uint32_t                    field_F0;
    uint32_t                    field_F4;
    uint32_t                    field_F8;
    CExoLocString               area_name;
    CExoString                  area_tag;
    uint32_t                    field_10C;
    uint32_t                    field_110;
    uint32_t                    field_114;
    uint32_t                    field_118;
    uint32_t                    field_11C;
    uint32_t                    field_120;
    uint32_t                    field_124;
    uint32_t                    field_128;
    uint32_t                    field_12C;
    uint32_t                    field_130;
    uint32_t                    field_134;
    uint32_t                    field_138;
    uint32_t                    field_13C;
    uint32_t                    field_140;
    uint32_t                    field_144;
    uint32_t                    field_148;
    uint32_t                    field_14C;
    uint32_t                    field_150;
    uint32_t                    field_154;
    uint32_t                    field_158;
    uint32_t                    field_15C;
    uint32_t                    field_160;
    uint32_t                    field_164;
    uint32_t                    field_168;
    uint32_t                    field_16C;
    uint32_t                    field_170;
    uint32_t                    field_174;
    uint32_t                    field_178;
    uint32_t                    field_17C;
    uint32_t                    field_180;
    uint32_t                    field_184;
    uint32_t                    field_188;
    uint32_t                    field_18C;
    uint32_t                    field_190;
    uint32_t                    field_194;
    CPathfindInformation *      area_pathfind_info;
    uint32_t                    field_19C;
    uint32_t                    field_1A0;
    uint32_t                    field_1A4;
    uint32_t                    field_1A8;
    uint32_t                    field_1AC;
    uint32_t                    field_1B0;
    uint32_t                    field_1B4;
    uint32_t                    field_1B8;
    uint32_t                    field_1BC;
    uint32_t                    field_1C0;
    uint32_t                    field_1C4;
    uint32_t                    field_1C8;
    uint32_t                    field_1CC;
    uint32_t                    field_1D0;
    uint32_t                    field_1D4;

    CNWSScriptVarTable          area_vartable;

    uint32_t                    field_1E0;
    uint32_t                    field_1E4;
    uint32_t                    area_ambient_sound;
    uint32_t                    field_1EC;
    uint32_t                    field_1F0;
    uint32_t                    field_1F4;
    uint32_t                    field_1FC;
    uint8_t                     field_200;
    uint8_t                     field_201;
    uint8_t                     field_202;
    uint8_t                     area_pvp_setting;
};

#endif /* _NX_NWN_STRUCT_CNWSAREA_ */

/* vim: set sw=4: */
