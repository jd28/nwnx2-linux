#include "NWNXLib.h"

CNWSArea *nwn_GetAreaByID(uint32_t id) {
    CGameObject *ob = nwn_GetObjectByID(id);
    return ob ? ob->vtable->AsNWSArea(ob) : NULL;
}

bool nwn_ClearLineOfSight(CNWSArea *area, Vector pointa, Vector pointb) {
    Vector v;
    uint32_t id;

    return !!CNWSArea__ClearLineOfSight(area, pointa, pointb, &v,
                                        &id, OBJECT_INVALID,
                                        OBJECT_INVALID, 1);
}

float nwn_GetGroundHeight(CNWSArea *area, CScriptLocation *loc) {
    return CNWSArea__ComputeHeight(area, loc->loc_position);
}

bool nwn_GetIsWalkable(CNWSArea *area, CScriptLocation *loc) {
    CPathfindInformation *pfi = area->area_pathfind_info;
    if (pfi == NULL) return false;

    return CNWSArea__TestSafeLocationPoint(area, loc->loc_position, pfi);
}
