#include "NWNXLib.h"

CNWSWaypoint *nwn_GetWaypointByID(uint32_t id) {
    CGameObject *ob = nwn_GetObjectByID(id);
    return ob ? ob->vtable->AsNWSWaypoint(ob) : NULL;
}
