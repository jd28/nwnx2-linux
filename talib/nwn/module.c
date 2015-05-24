#include "NWNXLib.h"

CNWSModule *nwn_GetModule() {
    return CServerExoAppInternal__GetModule((*NWN_AppManager)->app_server->srv_internal);
}
