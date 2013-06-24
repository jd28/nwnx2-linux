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
#include <sstream>
#include <functional>

extern PLUGINLINK *pluginLink;

CNWNXItems::CNWNXItems() {
    confKey = "ITEMS";
    in_script = false;

    std::fill_n(event_scripts, ITEMS_EVENT_NUM, "jmd_items");
}

CNWNXItems::~CNWNXItems() {}

const char *CNWNXItems::GetConf(char* key){
    return (*nwnxConfig)[confKey][key].c_str();
}

void CNWNXItems::FireEvent(int32_t type, uint32_t obj_id, uint32_t item_id) {
    event.type       = type;
    event.object     = obj_id;
    event.item       = item_id;
    event.use_result = false;

    in_script = true;

    int notifyRet = NotifyEventHooks(hEquipEvent, (WPARAM)&event, 0);
    // Someone else has handled the event.
    if ( !notifyRet ) {
        nwn_ExecuteScript(event_scripts[type].c_str(), obj_id);
    }

    in_script = false;
}

bool CNWNXItems::ItempropEvent(CNWSCreature *obj, CNWSItem *item, CNWItemProperty *ip, bool removal, bool preapply) {
    in_script = true;

    ip_event.obj = obj;
    ip_event.item = item;
    ip_event.ip = ip;
    ip_event.suppress = false;
    ip_event.remove = removal;
    ip_event.preapply = preapply;

    int notifyRet = NotifyEventHooks(hOnItemPropertyEvent, (WPARAM)&ip_event, 0);

    if ( !notifyRet                       &&
         !ip_scripts[ip->ip_type].empty() &&
         ip_scripts.find(ip->ip_type) != ip_scripts.end() ) {
        nwn_ExecuteScript((char*)ip_scripts[ip->ip_type].c_str(), obj->obj.obj_id);
    }

    in_script = false;

    return ip_event.suppress;
}


bool CNWNXItems::OnCreate (gline *config, const char* LogDir)
{
    char log[128];

    // call the base class function
    sprintf (log, "%s/nwnx_items.txt", LogDir);
    if (!CNWNXBase::OnCreate(config,log))
        return false;

    // write copy information to the log file
    Log (0, "NWNX Items v0.2\n");
    Log (0, "(c) 2012 by jmd\n");

    // Plugin Items
    if(!pluginLink){
        Log (0, "Plugin link not accessible\n");
    }
    else {
        Log (0, "Plugin link: %08lX\n", pluginLink);

    }

    hEquipEvent = CreateHookableEvent("NWNX/Items/Event");
    hOnItemPropertyEvent = CreateHookableEvent("NWNX/Items/ItemPropEvent");

    //HANDLE handleExamineEvent = HookEvent("NWNX/Events/ExamineEvent", Handle_ExamineEvent);
    //if (!handleExamineEvent) {
    //    Log(0, "Cannot hook NWNX/Events/ExamineEvent!\n");
    //}

    talib_init();
    hook_functions();

    return true;
}

char* CNWNXItems::OnRequest (char* gameObject, char* Request, char* Parameters){
    Log(2,"Request: \"%s\"\n", Request);
    Log(2,"Params:  \"%s\"\n", Parameters);

    return HandleRequest(reinterpret_cast<CGameObject*> (gameObject),
                         Request, Parameters);
}

unsigned long CNWNXItems::OnRequestObject (char *gameObject, char* Request){
    Log(2,"ObjRequest: \"%s\"\n",Request);
    return HandleRequestObject(reinterpret_cast<CGameObject*> (gameObject),
                               Request);
}

bool CNWNXItems::OnRelease (){
    Log (0, "o Shutdown.\n");
    return true;
}
