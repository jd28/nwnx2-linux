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

#ifndef NWNX_SOLSTICE_H
#define NWNX_SOLSTICE_H

#include "NWNXLib.h"
#include "talib/all.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "nwnx_modules_ext.h"
#include "lua_funcs.h"
#include "solstice_funcs.h"
#include "profiler/profiler.h"
#include "talib/effects/itemprop.h"

bool hook_functions();

char* HandleRequest(CGameObject *ob, const char *request, char *value);
    
int            Local_RunLuaScript(char *script, uint32_t id);
ChatMessage   *Local_GetLastChatMessage();
CombatMessage *Local_GetLastCombatMessage();
EventEffect   *Local_GetLastEffectEvent();
EquipEvent    *Local_GetLastEquipEvent();
EventItemprop *Local_GetLastItemPropEvent();
Event         *Local_GetLastNWNXEvent();
void           Local_NWNXLog(int level, const char* log);

#ifdef __cplusplus
}

#include "NWNXBase.h"
#include <string>

bool init_event_handles();

int Handle_ChatMessage(WPARAM p, LPARAM a);
int Handle_CombatMessage(WPARAM p, LPARAM a);
int Handle_ConversationEvent(WPARAM p, LPARAM a);
int Handle_EffectEvent(WPARAM p, LPARAM a);
int Handle_EquipEvent(WPARAM p, LPARAM a);
int Handle_Event(WPARAM p, LPARAM a);
int Handle_ItemPropEvent(WPARAM p, LPARAM a);
int Handle_PluginsLoaded(WPARAM p, LPARAM a);

int Hook_RunScriptStart(CVirtualMachine *vm, CExoString *script, nwn_objid_t id, int a);
void Hook_RunScriptEnd();
void Hook_RunScriptSituationStart(CVirtualMachine *vm, void *script, uint32_t obj, int a);
void Hook_RunScriptSituationEnd();
int8_t Hook_GetFeatRemainingUses(CNWSCreatureStats *stats, uint16_t feat);
int8_t Hook_GetFeatTotalUses(CNWSCreatureStats *stats, uint16_t feat);
int Hook_GetRunScriptReturnValue(CVirtualMachine *vm, int* a, void** b);
void    Hook_SetCombatMode(CNWSCreature *cre, int8_t mode, int32_t change);
int32_t Hook_ToggleMode(CNWSCreature *cre, uint8_t mode);

class CNWNXSolstice : public CNWNXBase
{
public:
    CNWNXSolstice();
    ~CNWNXSolstice();
    
    std::string GetConf(const char* key);
    bool InitializeEventHandlers();
    bool OnCreate(gline *nwnxConfig, const char *LogDir=NULL);
    char* OnRequest (char* gameObject, char* Request, char* Parameters);
    //unsigned long OnRequestObject (char *gameObject, char* Request);
    bool OnRelease();

    bool bHooked;
    int            in_conditional_script;
    int            lua_last_return;
    Event         *last_event;
    CombatMessage *last_combat_msg;
    ChatMessage   *last_chat_msg;
    EventItemprop *last_ip_event;
    EventEffect   *last_effect_event;
    EquipEvent    *last_equip_event;
};
#endif

#endif /* NWNX_SOLSTICE_H */

