#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_EffectEvent(WPARAM p, LPARAM a) {
    EventEffect *eff = (EventEffect *)p;

    if(eff->eff == NULL){
        solstice.Log(0, "CGameEffect is NULL\n");
        return 0;
    }
    else if(eff->obj == NULL){
        solstice.Log(0, "CGameEffect is NULL\n");
        return 0;
    }

    solstice.last_effect_event = eff;

    lua_getglobal(L, "NWNXEffects_HandleEffectEvent");
    if (lua_pcall(L, 0, 1, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXEffects_HandleEffectEvent : %s\n", lua_tostring(L, -1));
        return 0;
    }

    int result = lua_toboolean(L, -1);
    lua_pop(L, 1);

    return result;
};
