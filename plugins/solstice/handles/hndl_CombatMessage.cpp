#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_CombatMessage(WPARAM p, LPARAM a) {
    CombatMessage *msg = (CombatMessage *)p;

    solstice.last_combat_msg = msg;

    if(!nl_pushfunction(L, "__HandleCombatMessage"))
        return 0;

    if (lua_pcall(L, 0, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: __HandleCombatMessage : %s\n", lua_tostring(L, -1));
        return 0;
    }

    msg->suppress = lua_toboolean(L, -1);
    lua_pop(L, 1);

    solstice.Log(3, "SOLSTICE: Handle_CombatMessage : to: %X, type: %d, subtype: %d, suppress: %d\n",
		 msg->to, msg->type, msg->subtype, msg->suppress);

    return 1;
}
