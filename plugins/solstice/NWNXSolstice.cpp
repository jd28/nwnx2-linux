/***************************************************************************
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

#include "NWNXSolstice.h"

static int dolibrary (lua_State *L, const char *name) {
    lua_getglobal(L, "require");
    lua_pushstring(L, name);
    return lua_pcall(L, 1, 0, 0);
}

extern PLUGINLINK *pluginLink;

lua_State *L = NULL;

CNWNXSolstice::CNWNXSolstice(){
    confKey = strdup("SOLSTICE");
    bHooked = 1;
    lua_last_return = -1;
}

CNWNXSolstice::~CNWNXSolstice(){
}

std::string CNWNXSolstice::GetConf(const char* key) {
    return (*nwnxConfig)[confKey][key];
}

bool CNWNXSolstice::OnCreate(gline *config, const char *LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_solstice.txt", LogDir);


    // call the base class function
    if (!CNWNXBase::OnCreate(config,log))
        return false;

    //Add in this hack...to make sure the lua symbols are add to the
    //global table.  Before lua C modules were not working. 
    //void *res = dlopen("libluajit-5.1.so", RTLD_NOW | RTLD_GLOBAL);
    //if ( !res ) {
    //     Log (0, "ERROR: libluajit-5.1.so not installed!\n");
    //     return false;
    //}
    
    // Plugin Events
    if(!pluginLink){
	Log (0, "Plugin link not accessible\n");
        return false;
    }
    else {
	Log (0, "Plugin link: %08lX\n", pluginLink);
    }

    HANDLE handlePluginsLoaded = HookEvent("NWNX/Core/PluginsLoaded", Handle_PluginsLoaded);
    if (!handlePluginsLoaded) {
        Log(0, "Cannot hook plugins loaded event!\n");
	return false;
    }

#ifdef NWNX_SOLSTICE_PROFILE
    profiler_create("profile.txt");
#endif

    Log(0,"NWNX Solstice v0.2\n");
    Log(0,"(c) by jmd (jmd2028 at gmail dot com, 2011-2012)\n");

    L = lua_open();
    luaL_openlibs(L);

    std::string dir = GetConf("script_dir");
    if ( dir.empty() ) {
        dir = "solstice/preload";
    }
    else {
        dir += "/preload";
    }

    int status = dolibrary(L, dir.c_str());
    if (status) {
        /* If something went wrong, error message is at the top of */
        /* the stack */
        Log(0, "Couldn't load file: %s\n", lua_tostring(L, -1));
    }

    bHooked = hook_functions();

    unsigned char *eff_num_ints = (unsigned char*)0x0817dd37;
    nx_hook_enable_write(eff_num_ints, 1);
    memset((void *)eff_num_ints, (uint8_t)10, 1);


    Log(0,"* Module loaded successfully.\n");
    return true;
}

char* CNWNXSolstice::OnRequest (char *gameObject, char* Request, char* Parameters) {
    Log(2,"(S) Request: \"%s\"\n",Request);
    Log(3,"(S) Params:  \"%s\"\n",Parameters);

    if ( !gameObject ) { return NULL; }
    
    HandleRequest(reinterpret_cast<CGameObject*>(gameObject),
                  Request, Parameters);
    
    return NULL;
}

bool CNWNXSolstice::OnRelease ()
{
#ifdef NWNX_SOLSTICE_PROFILE
    profiler_destroy();
#endif

    int nKBytes = lua_gc(L, LUA_GCCOUNT, 0); 
    Log (0, "o Shutdown.. Memory: %d Kb\n", nKBytes);

    return true;
}

bool CNWNXSolstice::InitializeEventHandlers(){
    bool result = true;

    HANDLE handleChatMessage = HookEvent("NWNX/Chat/ChatMessage", Handle_ChatMessage);
    if (!handleChatMessage) {
        Log(0, "Cannot hook NWNX/Chat/ChatMessage!\n");
	result = false;
    }

    HANDLE handleCCMessage = HookEvent("NWNX/Chat/CCMessage", Handle_CombatMessage);
    if (!handleCCMessage) {
        Log(0, "Cannot hook NWNX/Chat/CombatMessage!\n");
	result = false;
    }

    HANDLE handleEffectEvent = HookEvent("NWNX/Effects/EffectEvent", Handle_EffectEvent);
    if (!handleEffectEvent) {
        Log(0, "Cannot hook NWNX/Effects/EffectEvent!\n");
	result = false;
    }

    HANDLE handleEquipEvent = HookEvent("NWNX/Items/Event", Handle_EquipEvent);
    if (!handleEquipEvent){
        Log(0, "Cannot hook NWNX/Equips/Event!\n");
	result = false;
    }

    HANDLE handleConversationEvent = HookEvent("NWNX/Events/ConversationEvent", Handle_ConversationEvent);
    if (!handleConversationEvent) {
        Log(0, "Cannot hook NWNX/Events/ConversationEvent!\n");
	result = false;
    }

    HANDLE handleEvent = HookEvent("NWNX/Events/Event", Handle_Event);
    if (!handleEvent) {
        Log(0, "Cannot hook NWNX/Events/Event!\n");
	result = false;
    }

    HANDLE handleItemPropEvent = HookEvent("NWNX/Items/ItemPropEvent", Handle_ItemPropEvent);
    if (!handleItemPropEvent){
        Log(0, "Cannot hook NWNX/Effects/ItemPropEvent!\n");
	result = false;
    }

    return result;
}