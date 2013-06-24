/***************************************************************************
    NWN Extender - Hook run script function in the server
    Copyright (C) 2003 Ingmar Stieger (Papillon)
    email: papillon@blackdagger.com
	Linux port - (c) virusman (virusman@virusman.ru)
        Moved to library - jd28

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

#ifndef _NWNX_PROFILER_
#define _NWNX_PROFILER_

#include <stdint.h>

const int MAX_CALLDEPTH = 1024;
const int DATEBUFFERLENGTH = 256;

#ifdef __cplusplus
extern "C" {
#endif

void profiler_flush_stats(uint32_t);
void profiler_start_timer(char *, int);
void profiler_stop_timer();
int profiler_create(const char* file);
void profiler_destroy();

#ifdef __cplusplus
}
#endif

#endif
