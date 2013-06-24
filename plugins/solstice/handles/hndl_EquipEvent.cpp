#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_EquipEvent(WPARAM p, LPARAM a) {
    EquipEvent *ev = (EquipEvent *)p;
    solstice.last_equip_event = ev;

    lua_getglobal(L, "NWNXEquips_HandleEquipEvent");
    if (lua_pcall(L, 0, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXEquips_HandleEquipEvent : %s\n", lua_tostring(L, -1));
        return 0;
    }    

    int result = lua_toboolean(L, -1); 
    lua_pop(L, 1);

    return result;
};
