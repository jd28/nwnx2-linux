/***************************************************************************
    Copyright (C) 2011-2013 jmd (jmd2028 at gmail dot com)

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

#ifndef NWNX_LEVELS_H
#define NWNX_LEVELS_H

#include "NWNXLib.h"
#include "talib/nwn/all.h"

void Func_GetMaxLevelLimit  (CGameObject *ob, char *value);
void Func_LevelUp           (CGameObject *ob, char *value);
void Func_LevelDown         (CGameObject *ob, char *value);
void Func_ModifyXPDirect    (CGameObject *ob, char *value);
void Func_SetMaxLevelLimit  (CGameObject *ob, char *value);
void Func_SetXPDirect       (CGameObject *ob, char *value);
void Func_GetMeetsFeatRequirements (CGameObject *ob, char *value);

int8_t Hook_GetSpellGain(CNWClass *cls, uint8_t level, uint8_t spell_level);
uint8_t Hook_GetSpellsKnownPerLevel(CNWClass *cls, uint8_t level, int8_t sp_level, int8_t class_type, uint16_t race, uint8_t cha);
void Hook_SummonAnimalCompanion(CNWSCreature *cre);
void Hook_SummonFamiliar(CNWSCreature *cre);

#include "NWNXBase.h"

class CNWNXLevels : public CNWNXBase {
public:
    CNWNXLevels();
    virtual ~ CNWNXLevels();

    bool OnCreate (gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest (char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject (char *gameObject, char *Request);

    // bool OnRelease  ();
};

#endif /* NWNX_LEVELS_H */
