#include "NWNXLib.h"

CNWSPlayer *nwn_GetPlayerByPlayerID (uint32_t id) {
    return CServerExoApp__GetClientObjectByPlayerId((*NWN_AppManager)->app_server, id, 1);
}

void nwn_BootPCWithMessage(nwn_objid_t id, int32_t strref) {
    CNWSPlayer *pl = nwn_GetPlayerByPlayerID(id);

    if (pl) {
        CNetLayer__DisconnectPlayer((*NWN_AppManager)->app_server->srv_internal->srv_network,
                                    pl->pl_id, strref, 1);
    }
}

char *nwn_GetPCFileName(uint32_t id)
{
    const CNWSPlayer *pl = CServerExoApp__GetClientObjectByObjectId((*NWN_AppManager)->app_server,id);
    if (pl == NULL) { return NULL; }
    return strndup(pl->pl_bicfile, 16);
}
