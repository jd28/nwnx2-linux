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

/* vim: set sw=4: */
#ifndef _NX_NWN_STRUCT_CSERVERAIMASTER_
#define _NX_NWN_STRUCT_CSERVERAIMASTER_

struct CServerAIMaster_s {
	uint32_t                    field_00;                /* 00 */
	uint32_t                    field_04;                /* 04 */
	uint32_t                    field_08;                /* 08 */
	uint32_t                    field_0C;                /* 0C */
	uint32_t                    field_10;                /* 10 */
	uint32_t                    field_14;                /* 14 */
	uint32_t                    field_18;                /* 18 */
	uint32_t                    field_1C;                /* 1C */
	uint32_t                    field_20;                /* 20 */
	uint32_t                    field_24;                /* 24 */
	uint32_t                    field_28;                /* 28 */
	uint32_t                    field_2C;                /* 2C */
	uint32_t                    field_30;                /* 30 */
	uint32_t                    field_34;                /* 34 */
	uint32_t                    field_38;                /* 38 */
	uint32_t                    field_3C;                /* 3C */
	uint32_t                    field_40;                /* 40 */
	uint32_t                    field_44;                /* 44 */
	uint32_t                    field_48;                /* 48 */
	uint32_t                    field_4C;                /* 4C */
	uint32_t                    field_50;                /* 50 */
	uint32_t                    field_54;                /* 54 */
	CNWSEffectListHandler       *saim_eff_list_handler;  /* 58 */
};

#endif /* _NX_NWN_STRUCT_CSERVERAIMASTER_ */
