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

#ifndef _NX_NWN_STRUCT_CNWSKILL_
#define _NX_NWN_STRUCT_CNWSKILL_

struct CNWSkill_s {
    uint32_t                   sk_name_strref;
    uint32_t                   sk_desc_strref;
    uint32_t                   sk_category;
    uint32_t                   sk_max_cr;
    CExoString                 sk_icon;
    uint32_t                   sk_ability;
    uint32_t                   sk_hostile;
    uint32_t                   sk_untrained;
    uint32_t                   sk_armor_check;
    uint32_t                   sk_all_can_use;
};

#endif /* _NX_NWN_STRUCT_CNWSKILL_ */

/* vim: set sw=4: */
