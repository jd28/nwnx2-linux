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

#ifndef _NX_NWN_STRUCT_CNWSENCOUNTER_
#define _NX_NWN_STRUCT_CNWSENCOUNTER_

struct CNWSEncounter_s {
    CNWSObject     obj;
    uint8_t        field_1C0;
    uint8_t        field_1C1;
    uint8_t        field_1C2;
    uint8_t        field_1C3;
    uint32_t       enc_faction;               /* 01C8 */
    CExoLocString  enc_localized_name;        /* 01CC */
    uint8_t        enc_is_active;             /* 01D4 */
    uint8_t        field_1D5;
    uint8_t        field_1D6;
    uint8_t        field_1D7;
    uint8_t        enc_reset;                 /* 01D8 */
    uint8_t        field_1D9;
    uint8_t        field_1DA;
    uint8_t        field_1DB;
    int32_t        enc_reset_time;            /* 01DC */
    int32_t        enc_spawn_option;          /* 01E0 */
    int32_t        enc_difficulty;            /* 01E4 */
    int32_t        enc_difficulty_index;      /* 01E8 */
    int32_t        enc_rec_creatures;         /* 01EC */
    int32_t        enc_max_creatures;         /* 01F0 */
    int32_t        enc_number_spawned;        /* 01F4 */
    uint32_t       enc_heartbeat_day;         /* 01F8 */
    uint32_t       enc_heartbeat_time;        /* 01FC */
    uint32_t       enc_last_spawn_day;        /* 0200 */
    uint32_t       enc_last_spawn_time;       /* 0204 */
    uint8_t        enc_started;               /* 0208 */
    uint8_t        field_209;
    uint8_t        field_20A;
    uint8_t        field_20B;
    uint8_t        enc_exhausted;              /* 020C */
    uint8_t        field_20C;
    uint8_t        field_20D;
    uint8_t        field_20E;
    int32_t        enc_area_list_max_size;     /* 0210 */
    uint8_t        spacer[51];                 /* 0214 */
    CSpawnPoint   *enc_spawn_points;           /* 0248 */
    uint32_t       enc_spawn_points_len;       /* 024C */
    int32_t        enc_respawns;               /* 0250 */
    int32_t        enc_spawns_max;             /* 0254 */
    int32_t        enc_spawns_current;         /* 0258 */
    uint32_t       field_25C;
    uint32_t       field_260;
    float          enc_area_points;            /* 0264 */
    uint32_t       field_268;
    float          enc_spawn_pool_active;      /* 026C */
    nwn_objid_t    enc_last_entered;           /* 0270 */
    nwn_objid_t    enc_last_left;              /* 0274 */
    CExoString     enc_scripts[5];             /* 0278 */
    uint32_t       field_2A0;
    int32_t        enc_custom_script_id;       /* 02A4 */
    uint8_t        enc_player_only;            /* 02A8 */
    uint8_t        field_2A9;
    uint8_t        field_2AA;
    uint8_t        field_2AB;
};

#endif /* _NX_NWN_STRUCT_CNWSENCOUNTER_ */

/* vim: set sw=4: */
