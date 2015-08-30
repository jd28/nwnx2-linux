#include "NWNXSolstice.h"
#include "effects/pluginlink.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

int Handle_EffectsCustomApplyEvent(uintptr_t p)
{
    EffectsCustomApplyEvent *eff = reinterpret_cast<EffectsCustomApplyEvent*>(p);
    if (eff->effect == NULL) {
        solstice.Log(0, "CGameEffect is NULL\n");
        return 0;
    } else if (eff->object == NULL) {
        solstice.Log(0, "CGameEffect is NULL\n");
        return 0;
    }

    solstice.last_effect_apply_event = eff;

    if (!nl_pushfunction(L, "__NWNXEffectsHandleApplyEvent"))
        return 0;

    if (lua_pcall(L, 0, 1, 0) != 0) {
        solstice.Log(0, "SOLSTICE: __NWNXEffectsHandleEffectEvent : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return 0;
    }

    int result = lua_toboolean(L, -1);
    lua_pop(L, 1);

    return result;

}

int Handle_EffectsCustomRemoveEvent(uintptr_t p)
{
    EffectsCustomRemoveEvent *eff = reinterpret_cast<EffectsCustomRemoveEvent*>(p);
    if (eff->effect == NULL) {
        solstice.Log(0, "CGameEffect is NULL\n");
        return 0;
    } else if (eff->object == NULL) {
        solstice.Log(0, "CGameEffect is NULL\n");
        return 0;
    }

    solstice.last_effect_remove_event = eff;

    if (!nl_pushfunction(L, "__NWNXEffectsHandleRemoveEvent"))
        return 0;

    if (lua_pcall(L, 0, 1, 0) != 0) {
        solstice.Log(0, "SOLSTICE: __NWNXEffectsHandleRemoveEvent : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return 0;
    }

    int result = lua_toboolean(L, -1);
    lua_pop(L, 1);

    return result;
}
