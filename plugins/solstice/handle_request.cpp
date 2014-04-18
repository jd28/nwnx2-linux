#include "NWNXSolstice.h"
#include "funcs.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

char* HandleRequest(CGameObject *ob, const char *request, char *value) {
    uint32_t obj = OBJECT_INVALID;

#define M(str, lit)                                                     \
    strncmp((str), "" lit, (sizeof (lit)/sizeof(char)) - 1) == 0

    if( M(request, "REMOVEFROMCACHE") ){
        Func_RemoveObjectFromCache(ob, value);
    }
    else if ( M(request, "UPDATECOMBATINFO") ) {
        if(!nl_pushfunction(L, "NWNXSolstice_UpdateCombatInfo"))
            return NULL;
        sscanf(value, "%x", &obj);
        lua_pushinteger(L, obj);

        if (lua_pcall(L, 1, 0, 0) != 0){
            solstice.Log(0, "SOLSTICE: NWNXSolstice_UpdateCombatInfo : %s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }

    return NULL;
#undef M
}
