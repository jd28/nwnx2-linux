#include "NWNXLib.h"

int32_t nwn_GetFactionId(uint32_t id){
    int32_t fac;

    CServerExoAppInternal__GetFactionOfObject((*NWN_AppManager)->app_server->srv_internal,
                                              id, &fac);
    return fac;
}

void nwn_SetFactionId(nwn_objid_t id, int32_t faction){
    CNWSFaction *fac;
    CFactionManager *facman = (*NWN_AppManager)->app_server->srv_internal->srv_factions;
    fac = CFactionManager__GetFaction(facman, faction);
    CNWSFaction__AddMember(id, 0);
}
