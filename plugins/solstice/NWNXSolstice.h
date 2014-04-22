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

#include <unordered_map>

#include "NWNXLib.h"
#include "talib/nwn/all.h"
#include "consts.h"
#include "object/creature.h"


#ifdef __cplusplus
extern "C" {
#endif
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "nwnx_modules_ext.h"
#include "lua_funcs.h"
#include "solstice_funcs.h"
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

void           Local_DeleteCreature(uint32_t id);
Creature      *Local_GetCreature(uint32_t id);
CombatInfo    *Local_GetCombatInfo(uint32_t id);
CGameEffect   *Local_GetPolyEffect();
C2DA          *Local_GetPoly2da();

#ifdef __cplusplus
}

#include "NWNXBase.h"
#include <string>

bool init_event_handles();

int Handle_ChatMessage(WPARAM p, LPARAM a);
int Handle_CombatMessage(WPARAM p, LPARAM a);
int Handle_ConversationEvent(WPARAM p, LPARAM a);
int Handle_CustomEffectEvent(WPARAM p, LPARAM a);
int Handle_EquipEvent(WPARAM p, LPARAM a);
int Handle_Event(WPARAM p, LPARAM a);
int Handle_ItemPropEvent(WPARAM p, LPARAM a);
int Handle_PluginsLoaded(WPARAM p, LPARAM a);

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
    void Initialize();

    bool bHooked;
    int            in_conditional_script;
    int            lua_last_return;
    Event         *last_event;
    CombatMessage *last_combat_msg;
    ChatMessage   *last_chat_msg;
    EventItemprop *last_ip_event;
    EventEffect   *last_effect_event;
    EquipEvent    *last_equip_event;
    uint32_t       lua_attacks = 0;
    uint32_t       nwn_attacks = 0;
    uint64_t       lua_time = 0;
    uint64_t       nwn_time = 0;

    uint32_t       updates = 0;
    uint64_t       update_time = 0;
    CGameEffect   *poly_eff;

    std::unordered_map<uint32_t, Creature> cache;
};
#endif

#endif /* NWNX_SOLSTICE_H */
