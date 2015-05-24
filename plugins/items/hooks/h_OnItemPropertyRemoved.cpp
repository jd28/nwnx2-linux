/***************************************************************************
    Copyright (C) 2011-2012 jmd ( jmd2028 at gmail dot com )

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
#include "hooks.h"

extern CNWNXItems items;

// Item property removal cannot be supressed.
int Hook_OnItemPropertyRemoved(CServerAIMaster *ai, CNWSItem *item, CNWItemProperty *ip, CNWSCreature *cre, uint32_t slot){
    if( cre == NULL || item == NULL || ip == NULL ) {
        return 0;
    }

    int result = CServerAIMaster__OnItemPropertyRemoved_orig(ai, item, ip, cre, slot);

    if ( !items.in_script ) {
        items.ItempropEvent(cre, item, ip, true, slot);
    }

    return result;
}
