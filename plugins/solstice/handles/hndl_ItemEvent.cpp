#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_ItemEvent(WPARAM p, LPARAM a) {
    ItemEvent *ev = (ItemEvent *)p;
    solstice.last_item_event = ev;

    lua_getglobal(L, "__NWNXItemsHandleItemEvent");
    if (lua_pcall(L, 0, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: __NWNXItemsHandleItemEvent : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        solstice.Log(0, "SOLSTICE: __NWNXItemsHandleItemEvent : %s\n", lua_gettrace(L));
        return 0;
    }

    int result = lua_toboolean(L, -1);
    lua_pop(L, 1);

    return result;
};
