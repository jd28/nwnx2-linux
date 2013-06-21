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

#ifndef _NX_NWN_STRUCT_CNWITEMPROPERTY_
#define _NX_NWN_STRUCT_CNWITEMPROPERTY_

struct CNWItemProperty_s {
    uint16_t           ip_type;                /* 0000 */
    uint16_t           ip_subtype;             /* 0002 */
    uint8_t            ip_cost_table;          /* 0004 */
    uint8_t            field_5;                /* 0005 */
    uint16_t           ip_cost_value;          /* 0006 */
    uint8_t            ip_param_table;         /* 0008 */
    uint8_t            ip_param_value;         /* 0009 */
    uint8_t            ip_chance;              /* 000A */
    int8_t             field_B;                /* 000B */
    uint8_t            ip_useable;             /* 000C */
    uint8_t            field_D;                /* 000D */
    uint8_t            field_E;                /* 000E */
    uint8_t            field_F;                /* 000F */
    uint8_t            ip_uses_daily;          /* 0010 */
    uint8_t            ip_dur_type;            /* 0011 */
    uint8_t            field_12;               /* 0012 */
    uint8_t            field_13;               /* 0013 */
};

#endif /* _NX_NWN_STRUCT_CNWITEMPROPERTY_ */

/* vim: set sw=4: */
