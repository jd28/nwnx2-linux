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

#ifndef _NX_NWN_STRUCT_CNWRACE_
#define _NX_NWN_STRUCT_CNWRACE_

struct CNWRace_s {
    uint32_t  field_0000;       /* 0000 */
    uint32_t  field_0004;       /* 0004 */
    uint32_t  field_0008;       /* 0008 */
    uint32_t  field_000C;       /* 000C */
    uint32_t  ra_description;   /* 0010 */
    uint32_t  ra_biography;     /* 0014 */
    uint8_t   ra_str_adjust;    /* 0018 */
    uint8_t   ra_dex_adjust;    /* 0019 */
    uint8_t   ra_int_adjust;    /* 001A */
    uint8_t   ra_cha_adjust;    /* 001B */
    uint8_t   ra_wis_adjust;    /* 001C */
    uint8_t   ra_con_adjust;    /* 001D */
    uint8_t   ra_endurance;     /* 001E */
    uint8_t   padding_001F;     /* 001F */
    uint32_t  field_0020;       /* 0020 */
    uint32_t  field_0024;       /* 0024 */
    uint16_t *ra_feat_table;    /* 0028 */
    uint32_t  ra_age;           /* 002C */
    uint32_t  ra_appearance;    /* 0030 */
};

#endif /* _NX_NWN_STRUCT_CNWRACE_ */

/* vim: set sw=4: */
