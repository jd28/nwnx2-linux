/*
 *  (c) 2007
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

#ifndef _NX_NWN_STRUCT_CNWSPELL_
#define _NX_NWN_STRUCT_CNWSPELL_

struct CNWSpell_s {
    char       *sp_label;       // 0x00
    uint32_t    field_004;		// 0x04
    uint32_t    sp_name_tlk;	// 0x08
    uint32_t    sp_desc_tlk;	// 0x0C
    char        sp_icon_resref[16]; // 0x10
    uint32_t    sp_school;		// 0x20
    CExoString  sp_range;		// 0x24
    CExoString  sp_spellcomponent; // 0x2C
    uint32_t    sp_targettype;	// 0x34
    CExoString  sp_impactscript; // 0x38
    uint8_t     sp_level_bard;	// 0x40
    uint8_t     sp_level_cleric; // 0x41
    uint8_t     sp_level_druid; // 0x42
    uint8_t     sp_level_paladin; // 0x43
    uint8_t     sp_level_ranger; // 0x44
    uint8_t     sp_level_sorc;  // 0x45
    uint8_t     sp_level_wiz;   // 0x46
    uint8_t     sp_level_innate; // 0x47
    uint32_t    sp_conjtime;	// 0x48
    uint32_t    field_04C;
    uint32_t    field_050;
    uint32_t    field_054;
    uint32_t    field_058;
    uint8_t     field_05C;
    uint8_t     field_05D;
    char        sp_conjhandvisual[16]; // 0x5e
    char        field_06E[16];
    char        sp_conjsoundmale[16]; // 0x7e
    char        sp_conjsoundfemale[16]; // 0x8e
    char        sp_conjsoundvfx[16]; // 0x9e
    uint8_t     field_0AE;
    uint8_t     field_0AF;
    uint8_t     field_0B0;
    uint8_t     field_0B1;
    uint8_t     field_0B2;
    uint8_t     field_0B3;
    uint8_t     field_0B4;
    uint8_t     field_0B5;
    uint8_t     field_0B6;
    uint8_t     field_0B7;
    uint8_t     field_0B8;
    uint8_t     field_0B9;
    uint8_t     field_0BA;
    uint8_t     field_0BB;
    uint8_t     field_0BC;
    uint8_t     field_0BD;
    uint8_t     field_0BE;
    uint8_t     field_0BF;
    uint8_t     field_0C0;
    uint8_t     field_0C1;
    uint8_t     field_0C2;
    uint8_t     field_0C3;
    uint8_t     field_0C4;
    uint8_t     field_0C5;
    uint8_t     field_0C6;
    uint8_t     field_0C7;
    uint8_t     field_0C8;
    uint8_t     field_0C9;
    uint8_t     field_0CA;
    uint8_t     field_0CB;
    uint8_t     field_0CC;
    uint8_t     field_0CD;
    uint8_t     field_0CE;
    uint8_t     field_0CF;
    uint8_t     field_0D0;
    uint8_t     field_0D1;
    uint8_t     field_0D2;
    uint8_t     field_0D3;
    uint8_t     field_0D4;
    uint8_t     field_0D5;
    uint8_t     field_0D6;
    uint8_t     field_0D7;
    uint8_t     field_0D8;
    uint8_t     field_0D9;
    uint8_t     field_0DA;
    uint8_t     field_0DB;
    uint8_t     field_0DC;
    uint8_t     field_0DD;
    uint8_t     field_0DE;
    uint8_t     field_0DF;
    uint8_t     field_0E0;
    uint8_t     field_0E1;
    uint8_t     field_0E2;
    uint8_t     field_0E3;
    uint8_t     field_0E4;
    uint8_t     field_0E5;
    uint8_t     field_0E6;
    uint8_t     field_0E7;
    uint8_t     field_0E8;
    uint8_t     field_0E9;
    uint8_t     field_0EA;
    uint8_t     field_0EB;
    uint8_t     field_0EC;
    uint8_t     field_0ED;
    uint8_t     field_0EE;
    uint8_t     field_0EF;
    uint8_t     field_0F0;
    uint8_t     field_0F1;
    uint8_t     field_0F2;
    uint8_t     field_0F3;
    uint8_t     field_0F4;
    uint8_t     field_0F5;
    uint8_t     field_0F6;
    uint8_t     field_0F7;
    uint8_t     field_0F8;
    uint8_t     field_0F9;
    uint8_t     field_0FA;
    uint8_t     field_0FB;
    uint8_t     field_0FC;
    uint8_t     field_0FD;
    uint8_t     field_0FE;
    uint8_t     field_0FF;
    uint8_t     field_100;
    uint8_t     field_101;
    uint8_t     field_102;
    uint8_t     field_103;
    uint8_t     field_104;
    uint8_t     field_105;
    uint8_t     field_106;
    uint8_t     field_107;
    uint8_t     field_108;
    uint8_t     field_109;
    uint8_t     field_10A;
    uint8_t     field_10B;
    uint8_t     field_10C;
    uint8_t     field_10D;
    uint8_t     field_10E;
    uint8_t     field_10F;
    uint8_t     field_110;
    uint8_t     field_111;
    uint8_t     field_112;
    uint8_t     field_113;
    uint8_t     field_114;
    uint8_t     field_115;
    uint8_t     field_116;
    uint8_t     field_117;
    uint8_t     field_118;
    uint8_t     field_119;
    uint8_t     field_11A;
    uint8_t     field_11B;
    uint8_t     field_11C;
    uint8_t     field_11D;
    uint8_t     field_11E;
    uint8_t     field_11F;
    uint8_t     field_120;
    uint8_t     field_121;
    uint8_t     field_122;
    uint8_t     field_123;
    uint8_t     field_124;
    uint8_t     field_125;
    uint8_t     field_126;
    uint8_t     field_127;
    uint8_t     field_128;
    uint8_t     field_129;
    uint8_t     field_12A;
    uint8_t     field_12B;
    uint8_t     sp_subradial_spells;
    uint8_t     field_12D;
    uint8_t     field_12E;
    uint8_t     field_12F;
    uint8_t     sp_subradialspells_len;
    uint8_t     field_131;
    uint8_t     field_132;
    uint8_t     field_133;
    uint8_t     field_134;
    uint8_t     field_135;
    uint8_t     field_136;
    uint8_t     field_137;
    uint32_t    sp_id;
    uint8_t     field_13C;
    uint8_t     field_13D;
    uint8_t     field_13E;
    uint8_t     field_13F;
    uint8_t     field_140;
    uint8_t     field_141;
    uint8_t     field_142;
    uint8_t     field_143;
    uint8_t     sp_user_type;
    uint8_t     field_145;
    uint8_t     field_146;
    uint8_t     field_147;
    uint8_t     field_148;
    uint8_t     field_149;
    uint8_t     field_14A;
    uint8_t     field_14B;
    uint8_t     field_14C;
    uint8_t     field_14D;
    uint8_t     field_14E;
    uint8_t     field_14F;
    uint8_t     field_150;
    uint8_t     field_151;
    uint8_t     field_152;
    uint8_t     field_153;
    uint8_t     field_154;
    uint8_t     field_155;
    uint8_t     field_156;
    uint8_t     field_157;
    uint8_t     field_158;
    uint8_t     field_159;
    uint8_t     field_15A;
    uint8_t     field_15B;
    uint8_t     field_15C;
    uint8_t     field_15D;
    uint8_t     field_15E;
    uint8_t     field_15F;
    uint8_t     field_160;
    uint8_t     field_161;
    uint8_t     field_162;
    uint8_t     field_163;
};

#endif // _NX_NWN_STRUCT_CNWSPELL_
