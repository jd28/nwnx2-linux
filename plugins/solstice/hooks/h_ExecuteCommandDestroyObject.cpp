#include "NWNXSolstice.h"

extern lua_State *L;
extern CNWNXSolstice solstice;

int32_t Hook_ExecuteCommandDestroyObject(CNWVirtualMachineCommands *vm_cmds,
                                         int cmd, int args) {
    int result = 0;
    float delay = 0.0;
    uint32_t obj_id;

    if ( CVirtualMachine__StackPopObject(*NWN_VirtualMachine, &obj_id) &&
         (args != 2 || CVirtualMachine__StackPopFloat(*NWN_VirtualMachine, &delay)) ) {

        if(nl_pushfunction(L, "_SOL_DESTROY_OBJECT")) {
            lua_pushinteger(L, obj_id);
            lua_pushnumber(L, delay);

            if (lua_pcall(L, 2, 0, 0) != 0){
                solstice.Log(0, "ERROR: Destroying Object %x %s\n", obj_id, lua_tostring(L, -1));
            }
        }

        uint32_t day, time;
        CWorldTimer *timer = (*NWN_AppManager)->app_server->srv_internal->srv_time_world;
        day = CWorldTimer__GetCalendarDayFromSeconds(timer, delay);
        time = CWorldTimer__GetTimeOfDayFromSeconds(timer, delay);

        CServerAIMaster *ai_master = (*NWN_AppManager)->app_server->srv_internal->srv_ai;
        CServerAIMaster__AddEventDeltaTime(ai_master, day, time, vm_cmds->vmc_object_id,
                                           obj_id, EVENT_DESTROY_OBJECT, 0);

    }
    else {
        result = -639;
    }
    return result;
}
