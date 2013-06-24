
/***************************************************************************
    NWNX Items
    (c) 2012-2013 jmd (jmd2028 at gmail dot com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***************************************************************************/

#include "NWNXItems.h"
#include "talib/itemprop/itemprops.h"
#include <algorithm>
#include <sstream>

extern CNWNXItems items;

std::string Local_GetItemPropString(CNWSItem *it) {
    const char *d = nwn_GetLocalString(&it->obj.obj_vartable,	
                                       "NWNX_ITEMS_PROPS");
    int32_t version = nwn_GetLocalInt(&it->obj.obj_vartable,	
                                      "NWNX_ITEMS_IP_VER");
    
    if ( !d || !*d ) {
        std::vector<std::string> strs;

        strs.reserve(it->it_active_ip_len + it->it_passive_ip_len);

        for ( size_t i = 0; i < it->it_active_ip_len; ++i ) {
            CNWItemProperty& ip = it->it_active_ip[i];
            auto res = ItemProperties::toString(&ip, version);
            strs.push_back(res.second);
        }

        for ( size_t i = 0; i < it->it_passive_ip_len; ++i ) {
            CNWItemProperty& ip = it->it_passive_ip[i];
            auto res = ItemProperties::toString(&ip, version);
            strs.push_back(res.second);
        }

        std::sort(strs.begin(), strs.end());

        const char *description = "";
        bool has_description = false;

        std::stringstream ss;
        if ( it->it_desc_id_over.text ) {
            description = it->it_desc_id_over.text;
            has_description = true;
        }
        else if ( it->it_desc_id.strref != -1 ) {
            char *c = nwn_GetStringByStrref(it->it_desc_id.strref);
            ss << "Description:\n" << c << '\n';
            free(c);
        }
        else if ( (description = nwn_GetCExoLocStringText(&it->it_desc_id, 0)) ) { 
            has_description = true;
        }

        if ( has_description ) {
            ss << "Description:\n" << description << "\n\n";
        }

        ss << "Special Properties:";
        for ( auto i = strs.begin(); i != strs.end(); ++i ) {
            ss  << '\n' << *i;
        }

        std::string desc = ss.str();
        nwn_SetLocalString(&it->obj.obj_vartable,	
                           "NWNX_ITEMS_PROPS",
                           desc.c_str());
	
        return std::move(desc);
    }

    return d;
}
