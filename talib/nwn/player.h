#ifndef TALIB_PLAYER_H
#define TALIB_PLAYER_H

CNWSPlayer *nwn_GetPlayerByPlayerID (uint32_t id);
void        nwn_BootPCWithMessage(nwn_objid_t id, int32_t strref);
char       *nwn_GetPCFileName(uint32_t id);
#endif // TALIB_PLAYER_H
