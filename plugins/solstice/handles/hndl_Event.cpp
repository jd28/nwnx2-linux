#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_Event(uintptr_t p)
{
    solstice.last_event = (Event *)p;

    lua_getglobal(L, "__NWNXEventsHandleEvent");
    lua_pushinteger(L, solstice.last_event->type);

    if (lua_pcall(L, 1, 1, 0) != 0) {
        solstice.Log(0, "SOLSTICE: __NWNXEventsHandleEvent : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int result = lua_toboolean(L, -1);
    lua_pop(L, 1);

    solstice.Log(4, "Solstice Event Handler: Type: %d, Result: %d\n", solstice.last_event->type, result);

    return result;
}
