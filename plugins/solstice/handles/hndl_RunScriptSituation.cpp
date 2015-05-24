#include "NWNXSolstice.h"

extern lua_State *L;
extern CNWNXSolstice solstice;

int Handle_RunScriptSituation(uintptr_t p)
{
    CoreRunScriptSituationEvent *s = reinterpret_cast<CoreRunScriptSituationEvent *>(p);

    if(!s || !s->marker) {
        return 0;
    }

    int ctype = -1;
    double result = 0;

    solstice.Log(3, "Running Script Situation: %s\n", s->marker);

    if (strncmp(s->marker, "$", 1) == 0) {
        ctype = COMMAND_TYPE_DELAY;
    } else if (strncmp(s->marker, "&", 1) == 0) {
        ctype = COMMAND_TYPE_DO;
    } else if (strncmp(s->marker, "*", 1) == 0) {
        ctype = COMMAND_TYPE_REPEAT;
    } else {
        solstice.Log(4, "Script Situation: |%s| on %x\n", s->marker, s->objectId);
        return 0;
    }

    uint32_t temp = (*NWN_VirtualMachine)->vm_implementer->vmc_object_id;
    (*NWN_VirtualMachine)->vm_implementer->vmc_object_id = s->objectId;

    if (!nl_pushfunction(L, "_RUN_COMMAND"))
        return 0;

    lua_pushinteger(L, ctype);
    lua_pushinteger(L, s->token);
    lua_pushinteger(L, s->objectId);

    if (lua_pcall(L, 3, 1, 0) != 0) {
        solstice.Log(0, "Error: _RUN_COMMAND Type:%d : %s\n", ctype, lua_tostring(L, -1));
        lua_pop(L, 1);
        return 0;
    }

    result = lua_tonumber(L, -1);
    lua_pop(L, 1);

    (*NWN_VirtualMachine)->vm_implementer->vmc_object_id = temp;

    return 1;
    /*
    if(strcmp(s->marker, "$nwcpp") != 0) {
        return 0;
    }
    else {
        solstice.Log(4, "This situation isn't for us.\n");
    }

    if(ScriptManager::RunScriptSituation(s->token, s->objectId)) {
        s->suppress = true;
        return 1;
    }

    return 0;
    */
}
