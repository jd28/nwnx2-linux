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


#ifndef _NX_NWN_STRUCT_CNWSDOOR_
#define _NX_NWN_STRUCT_CNWSDOOR_

struct CNWSDoor_s {
    CNWSObject          obj;
    uint32_t            field_01C4;                     /* 01C4 */
    uint32_t            field_01C8;                     /* 01C8 */
    uint32_t            field_01CC;                     /* 01CC */
    uint32_t            field_01D0;                     /* 01D0 */
    uint32_t            field_01D4;                     /* 01D4 */
    uint32_t            field_01D8;                     /* 01D8 */
    uint32_t            field_01DC;                     /* 01DC */
    uint32_t            field_01E0;                     /* 01E0 */
    uint32_t            field_01E4;                     /* 01E4 */
    uint32_t            field_01E8;                     /* 01E8 */
    uint32_t            field_01EC;                     /* 01EC */
    uint32_t            field_01F0;                     /* 01F0 */
    uint32_t            field_01F4;                     /* 01F4 */
    uint32_t            field_01F8;                     /* 01F8 */
    uint32_t            field_01FC;                     /* 01FC */
    uint32_t            field_0200;                     /* 0200 */
    uint32_t            field_0204;                     /* 0204 */
    uint32_t            field_0208;                     /* 0208 */
    uint32_t            field_020C;                     /* 020C */
    uint32_t            field_0210;                     /* 0210 */
    uint32_t            field_0214;                     /* 0214 */
    uint32_t            field_0218;                     /* 0218 */
    uint32_t            field_021C;                     /* 021C */
    uint32_t            field_0220;                     /* 0220 */
    uint32_t            field_0224;                     /* 0224 */
    uint32_t            field_0228;                     /* 0228 */
    uint32_t            field_022C;                     /* 022C */
    uint32_t            field_0230;                     /* 0230 */
    uint32_t            field_0234;                     /* 0234 */
    uint32_t            field_0238;                     /* 0238 */
    uint32_t            door_appearance;                /* 023C */
    uint32_t            door_generic_type;              /* 0240 */
    char                door_conv[16];                  /* 0244 */
    uint32_t            door_bearing;                   /* 0254 */
    uint32_t            door_faction;                   /* 0258 */
    uint8_t             door_save_fort;                 /* 025C */
    uint8_t             door_save_reflex;               /* 025D */
    uint8_t             door_save_will;                 /* 025E */
    uint8_t             lock_open_dc;                   /* 025F */
    uint8_t             lock_dc;                        /* 0260 */
    uint8_t             field_0261;                     /* 0261 */
    uint8_t             door_hardness;                  /* 0262 */
    uint8_t             field_0263;                     /* 0263 */
    int32_t             lock_locked;                    /* 0264 */
    int32_t             lock_lockable;                  /* 0268 */
    uint32_t            field_026C;                     /* 026C */
    CExoString          lock_key_name;                  /* 0270 */
    CExoString          lock_key_required_msg;          /* 0278 */
    uint32_t            lock_key_required;              /* 0280 */
    uint32_t            field_0284;                     /* 0284 */
    uint32_t            field_0288;                     /* 0288 */
    uint32_t            field_028C;                     /* 028C */
    uint32_t            field_0290;                     /* 0290 */
    uint32_t            door_trapped;                   /* 0294 */
    uint8_t             trap_disarm_dc;                 /* 0298 */
    uint8_t             trap_detect_dc;                 /* 0299 */
    uint8_t             field_029A;                     /* 029A */
    uint8_t             field_029B;                     /* 029B */
    uint32_t            lock_key_remove;                /* 029C */
    uint32_t            trap_flagged;                   /* 02A0 */
    uint32_t            trap_basetype;                  /* 02A4 */
    uint32_t            trap_disarmable;                /* 02A8 */
    uint32_t            trap_detectable;                /* 02AC */
    uint32_t            trap_oneshot;                   /* 02B0 */
    uint32_t            trap_recoverable;               /* 02B4 */
    uint32_t            trap_active;                    /* 02B8 */
    uint32_t            trap_faction;                   /* 02BC */
    uint32_t            field_02C0;                     /* 02C0 */
    uint32_t            field_02C4;                     /* 02C4 */
    uint32_t            field_02C8;                     /* 02C8 */
    uint32_t            field_02CC;                     /* 02CC */
    uint32_t            field_02D0;                     /* 02D0 */
    uint32_t            field_02D4;                     /* 02D4 */
    uint32_t            field_02D8;                     /* 02D8 */
    uint32_t            field_02DC;                     /* 02DC */
    uint32_t            field_02E0;                     /* 02E0 */
    uint32_t            field_02E4;                     /* 02E4 */
    uint32_t            field_02E8;                     /* 02E8 */
    uint32_t            field_02EC;                     /* 02EC */
    uint32_t            field_02F0;                     /* 02F0 */
    uint32_t            field_02F4;                     /* 02F4 */
    uint32_t            field_02F8;                     /* 02F8 */
    uint32_t            field_02FC;                     /* 02FC */
    uint32_t            field_0300;                     /* 0300 */
    uint32_t            field_0304;                     /* 0304 */
    uint32_t            field_0308;                     /* 0308 */
    uint32_t            field_030C;                     /* 030C */
    uint32_t            field_0310;                     /* 0310 */
    uint32_t            field_0314;                     /* 0314 */
    uint32_t            field_0318;                     /* 0318 */
    uint32_t            field_031C;                     /* 031C */
    uint32_t            field_0320;                     /* 0320 */
    uint32_t            field_0324;                     /* 0324 */
    uint32_t            field_0328;                     /* 0328 */
    uint32_t            field_032C;                     /* 032C */
    uint32_t            field_0330;                     /* 0330 */
    uint32_t            field_0334;                     /* 0334 */
};

#endif /* _NX_NWN_STRUCT_CNWSDOOR_ */

/* vim: set sw=4: */
