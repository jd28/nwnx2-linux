/***************************************************************************
    Copyright (C) 2011 jmd ( jmd2028 at gmail dot com )

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

#ifndef NWNX_LUAJIT_LUA_FUNCS_H
#define NWNX_LUAJIT_LUA_FUNCS_H

#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#define COMMAND_TYPE_DELAY      0
#define COMMAND_TYPE_DO         1
#define COMMAND_TYPE_REPEAT     2
#define COMMAND_MARKER_DELAY    "$"
#define COMMAND_MARKER_DO       "&"
#define COMMAND_MARKER_REPEAT   "*"

void lua_stackdump(lua_State *stack);
const char *lua_gettrace(lua_State *L);
int nl_pushfunction(lua_State *L, const char* name);

#ifdef __cplusplus
}
#endif

#endif
