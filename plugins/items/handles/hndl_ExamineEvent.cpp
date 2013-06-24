/***************************************************************************
    Copyright (C) 2013 jmd (jmd2028 at gmail dot com)

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

extern CNWNXItems items;

int Handle_ExamineEvent(WPARAM p, LPARAM a) {
    EventExamine *ev = (EventExamine *)p;

    switch(ev->type){
    case OBJECT_TYPE_ITEM:
        return Local_ExamineItemEvent(ev);
    default:
        return 0;
    }
}