#include "NWNXSolstice.h"

extern lua_State *L;
extern CNWNXSolstice solstice;

void Func_LoadConstants(CGameObject *ob, char *value) {
    if(!nl_pushfunction(L, "NWNXSolstice_LoadConstants"))
        return;

    if (lua_pcall(L, 0, 0, 0) != 0){
        solstice.Log(0, "ERROR: %s\n", lua_tostring(L, -1));
    }
}
