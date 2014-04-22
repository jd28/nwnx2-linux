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

#include "NWNXEffects.h"
#include "funcs.h"

extern CNWNXEffects effects;

#define M(str, lit)                                                 \
    strncmp((str), "" lit, (sizeof (lit)/sizeof(char)) - 1) == 0

void HandleFunc(CGameObject *ob, char *func, char* value) {
    if ( M(func, "LOGEFFECTS") ) {
        Func_LogEffects(ob, value);
    }
    else if ( M(func, "SENDEFFECTS") ) {
        Func_SendEffects(ob, value);
    }
}

#undef M
