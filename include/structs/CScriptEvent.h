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

#ifndef _NX_NWN_STRUCT_CSCRIPTEVENT_
#define _NX_NWN_STRUCT_CSCRIPTEVENT_

struct CScriptEvent_s {
    uint16_t               evt_type;            /* 00 */
    uint16_t               field_02;            /* 02 */
    CExoArrayList_int32    evt_integers;        /* 04 */
    CExoArrayList_float    evt_floats;          /* 10 */
    CExoStringList         evt_strings;         /* 1C */
    CExoArrayList_uint32   evt_objects;         /* 28 */
};

#endif /* _NX_NWN_STRUCT_CSCRIPTEVENT_ */

/* vim: set sw=4: */
