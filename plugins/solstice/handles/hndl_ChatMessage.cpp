#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_ChatMessage(WPARAM p, LPARAM a) {
    ChatMessage *msg = (ChatMessage *)p;
    solstice.last_chat_msg = msg;
    
    if(!nl_pushfunction(L, "NWNXChat_HandleChatMessage"))
        return 0;

    if (lua_pcall(L, 0, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXChat_HandleChatMessage : %s\n", lua_tostring(L, -1));
	return 0;
    }

    bool result = lua_toboolean(L, -1);
    lua_pop(L, 1);
    return result;
};
