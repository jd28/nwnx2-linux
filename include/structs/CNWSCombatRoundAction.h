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

#ifndef _NX_NWN_STRUCT_CNWSCOMBATROUNDACTION_
#define _NX_NWN_STRUCT_CNWSCOMBATROUNDACTION_

struct CNWSCombatRoundAction_s {
    int32_t  cra_action_timer;      /* 00 */
    uint16_t cra_animation;         /* 04 */
    uint16_t field_06;              /* 06 */
    int32_t  cra_animation_time;    /* 08 */
    int32_t  cra_num_attacks;       /* 0C */
    uint8_t  cra_action_type;       /* 10 */
    uint8_t  field_11;              /* 10 */
    uint8_t  field_12;              /* 10 */
    uint8_t  field_13;              /* 10 */
    uint32_t cra_target;            /* 14 */
    uint8_t  cra_retargettable;     /* 18 */
    uint8_t  field_19;              /* 19 */
    uint8_t  field_1A;              /* 1A */
    uint8_t  field_1B;              /* 1B */
    uint32_t cra_inv_slot;          /* 1C */
    uint32_t cra_target_repository; /* 20 */
    uint8_t  cra_repository_x;      /* 24 */
    uint8_t  cra_repository_y;      /* 25 */   
};

#endif /* _NX_NWN_STRUCT_CNWSCOMBATROUNDACTION_ */

/* vim: set sw=4: */
