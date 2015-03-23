#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_ItemPropEvent(WPARAM p, LPARAM a) {
    EventItemprop *ip_event = (EventItemprop *)p;

    if(!ip_event){
        solstice.Log(0, "ip_event is null\n");
        return 0;
    }
    else if(ip_event->obj == NULL) {
        solstice.Log(0, "ip_event->obj is null\n");
        return 0;
    }
    else if(ip_event->item == NULL) {
        solstice.Log(0, "ip_event->item is null\n");
        return 0;
    }
    else if(ip_event->ip == NULL) {
        solstice.Log(0, "ip_event->ip is null");
        return 0;
    }

    solstice.last_ip_event = ip_event;

    lua_getglobal(L, "__NWNXItemsHandleItemPropEvent");
    lua_pushinteger(L, ip_event->ip->ip_type);

    if (lua_pcall(L, 1, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: __NWNXItemsHandleItemPropEvent : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int result = lua_toboolean(L, -1);
    lua_pop(L, 1);
    ip_event->suppress = result;

    return result;
}
