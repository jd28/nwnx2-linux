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

#ifndef _NX_NWN_STRUCT_CAPPMANAGER_
#define _NX_NWN_STRUCT_CAPPMANAGER_

struct CAppManager_s {
    u_int32_t                   field_00;

    CServerExoApp              *app_server;                 /* 0004 */
    CNWTileSetManager          *app_tileset_man;            /* 0008 */
    uint32_t                    field_0C;                   /* 000C */
    CObjectTableManager        *app_objtable_man;           /* 0010 */
    uint32_t                    field_14;                   /* 0014 */
    uint32_t                    field_18;                   /* 0018 */
    uint32_t                    app_tickcount;              /* 001C */
    uint32_t                    field_20;                   /* 0020 */
    uint32_t                    field_24;                   /* 0030 */
    uint32_t                    field_28;                   /* 0028 */
    uint32_t                    field_2C;                   /* 0030 */
    uint32_t                    field_30;                   /* 0030 */
    uint32_t                    field_34;                   /* 0034 */
    uint32_t                    field_38;                   /* 0038 */
};

#endif /* _NX_NWN_STRUCT_CAPPMANAGER_ */

/* vim: set sw=4: */
