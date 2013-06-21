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

#ifndef _NX_NWN_STRUCT_CNWSITEM_
#define _NX_NWN_STRUCT_CNWSITEM_

struct CNWSItem_s {
    uint8_t                     it_color[6];            /* 0000 */
    uint8_t                     field_06;
    uint8_t                     field_07;

    uint32_t                    it_baseitem;

    uint32_t                    field_0C;

    CNWSObject                  obj;

    uint32_t                    field_1D4;              /* 01D4 */
    uint32_t                    field_1D8;              /* 01D8 */
    uint32_t                    field_1DC;              /* 01DC */
    uint32_t                    field_1E0;              /* 01E0 */

    uint8_t                     it_identified;          /* 01E4 */
    uint8_t                     field_1E5;
    uint8_t                     field_1E6;
    uint8_t                     field_1E7;

    uint32_t                    field_1E8;              /* 01E8 */
    CNWItemProperty            *it_active_ip;           /* 01EC */
    uint32_t                    it_active_ip_len;
    uint32_t                    it_active_ip_alloc;
    CNWItemProperty            *it_passive_ip;           /* 01F8 */
    uint32_t                    it_passive_ip_len;
    uint32_t                    it_passive_ip_alloc;
    

    uint32_t                    it_charges;             /* 0204 */

    uint32_t                    it_cost_ided;           /* 0208 */
    uint32_t                    it_cost_unided;         /* 020C */

    uint32_t                    it_cost_add;            /* 0210 */

    uint32_t                    field_214;              /* 0214 */

    uint8_t                     it_model[22];           /* 0218 */

    uint8_t                     field_22E;
    uint8_t                     field_22F;

    uint32_t                    field_230;              /* 0230 */
    uint32_t                    field_234;              /* 0234 */
    uint32_t                    field_238;              /* 0238 */
    uint32_t                    field_23C;              /* 023C */
    uint32_t                    field_240;              /* 0240 */
    uint32_t                    it_possessor;           /* 0244 */
    uint32_t                    field_248;              /* 0248 */
    uint32_t                    field_24C;              /* 024C */
    CExoLocString               it_desc_id;             /* 0250 */
    CExoLocString               it_desc_unid;           /* 0258 */
    CExoString                  it_desc_id_over;        /* 0260 */
    CExoString                  it_desc_unid_over;      /* 0268 */
    uint32_t                    field_270;              /* 0270 */
    uint32_t                    field_274;              /* 0274 */
    uint32_t                    field_278;              /* 0278 */
    uint32_t                    field_27C;              /* 027C */
    uint32_t                    field_280;              /* 0280 */
    uint32_t                    field_284;              /* 0284 */

    uint8_t                     it_droppable;           /* 0288 */
    uint8_t                     field_289;
    uint8_t                     field_28A;
    uint8_t                     field_28B;

    uint32_t                    it_pickpocketable;      /* 028C */

    uint32_t                    it_cursed;              /* 0290 */

    uint32_t                    it_stacksize;           /* 0294 */

    uint8_t                     it_stolen;              /* 0298 */
    uint8_t                     field_299;
    uint8_t                     field_29A;
    uint8_t                     field_29B;

    uint32_t                    it_weight;              /* 029C */

    uint8_t                     field_2A0;              /* 02A0 */
    uint8_t                     field_2A1;              /* 02A0 */
    uint8_t                     it_wpn_vfx;             /* 02A2 */
};

#endif /* _NX_NWN_STRUCT_CNWSITEM_ */

/* vim: set sw=4: */
