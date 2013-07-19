#ifndef TALIB_AREA_H
#define TALIB_AREA_H

CNWSArea *nwn_GetAreaByID(uint32_t id);
bool      nwn_ClearLineOfSight(CNWSArea *area, Vector pointa, Vector pointb);
float     nwn_GetGroundHeight(CNWSArea *area, CScriptLocation *loc);
bool      nwn_GetIsWalkable(CNWSArea *area, CScriptLocation *loc);

#endif // TALIB_AREA_H
