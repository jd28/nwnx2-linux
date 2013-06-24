#include "NWNXSolstice.h"

extern lua_State *L;
extern CNWNXSolstice solstice;

int Local_RunLuaScript(char *script, uint32_t id){
    if(!nl_pushfunction(L, "_SOL_RUN_SCRIPT"))
        return 0;

    lua_pushstring(L, script);
    lua_pushinteger(L, id);

    if (lua_pcall(L, 2, 2, 0) != 0){
        solstice.Log(0, "ERROR: %s on %x %s\n", script, id, lua_tostring(L, -1));
        return 0;
    }
    int res = lua_tointeger(L, -1);
    solstice.lua_last_return = lua_tointeger(L, -2);
    lua_pop(L, 2);
    
    return res;
}
