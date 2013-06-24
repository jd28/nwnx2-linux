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
#include "talib/util/timer.h"

#include <sstream>

extern CNWNXItems items;

int Local_ExamineItemEvent(EventExamine *ev) {
    CNWMessage *msg = ev->msg;
    uint32_t pc_id = ev->pc->pl_id;
    CNWSItem *it = nwn_GetItemByID(ev->obj);

    CGameObject *obj = nwn_GetObjectByID(ev->pc->obj_id);
    CNWSCreature *cre = obj->vtable->AsNWSCreature(obj);

    bool is_dm = cre && cre->cre_stats->cs_is_dm;

    CNWMessage__CreateWriteMessage(msg, 128, pc_id, 1);
    
    if ( !it ) {
        CNWSMessage__WriteOBJECTIDServer((CNWSMessage *)msg, OBJECT_INVALID);
    }
    else {
        CNWSMessage__WriteOBJECTIDServer((CNWSMessage *)msg, it->obj.obj_id);
        CNWSMessage__WriteOBJECTIDServer((CNWSMessage *)msg, cre ? obj->id : OBJECT_INVALID);

        CNWMessage__WriteBOOL(msg, it->it_identified);

        if ( it->it_identified ) {
            bool canuse = cre && !!CNWSCreature__CanUseItem(cre, it, 0);
            CNWMessage__WriteBOOL(msg, canuse);
        }

        // Indicates using description override which is a CExoString.
        CNWMessage__WriteBOOL(msg, 1);

        if ( it->it_identified ) {
            uint64_t start = ClockGetTime();

            std::string desc = Local_GetItemPropString(it);
            char *d = strdup(desc.c_str());
            CNWMessage__WriteCExoString(msg, &d, 0x20);
	    
            uint64_t stop = ClockGetTime();
            items.Log(0, "Local_GetItemPropString time: %d\n", stop - start);
        }
        else {
            std::stringstream ss;
            bool has_description = false;
            const char *description;

            if ( it->it_desc_unid_over.text ) {
                description = it->it_desc_id_over.text;
                has_description = true;
            }
            else if ( it->it_desc_id.strref != 0xffffffff ) {
                char *c = nwn_GetStringByStrref(it->it_desc_id.strref);
                ss << "Description:\n" << c << '\n';
                free(c);
            }
            else if ( (description = nwn_GetCExoLocStringText(&it->it_desc_unid, 0)) ) { 
                has_description = true;
            }
	    
            if ( has_description ) {
                ss << "Description:\n" << description << "\n\n";
            }
            std::string desc = ss.str();
            char *d = strdup(desc.c_str());
            CNWMessage__WriteCExoString(msg, &d, 0x20);
        }

        bool using_irl   = !!(*NWN_AppManager)->app_server->srv_internal->srv_info->sri_using_irl;
        uint8_t min_level = 0;
        bool canuse      = false;

        if( using_irl && cre ) {
            min_level = CNWSItem__GetMinEquipLevel( it );
            if ( is_dm || nwn_GetHitDice(cre) >= min_level) {
                canuse = true;
            }
        }
	
        CNWMessage__WriteBOOL(msg, canuse);
        if ( !canuse ) {
            CNWMessage__WriteBYTE(msg, min_level, 8);
        }

        CNWMessage__WriteINT(msg, it->it_charges, 0x20);
        CNWMessage__WriteINT(msg, CNWSItem__GetWeight(it), 0x20);

        // Ignore DM item cost info...
        CNWMessage__WriteBOOL(msg, 0);

        if( it->it_identified ){
            // Default Engine code would be to send Item properties at this point,
            // but that is handled above.
            CNWMessage__WriteWORD(msg, 0, 0x10);
        }
    }

    unsigned char *ptr;
    uint32_t dunno;
    int result = 0;

    if (CNWMessage__GetWriteMessage(msg, &ptr, &dunno))
        result = CNWSMessage__SendServerToPlayerMessage((CNWSMessage *)msg, pc_id, 27, 2, ptr, dunno);

    ev->result = result;
    ev->bypass = true;

    return 1;
}
