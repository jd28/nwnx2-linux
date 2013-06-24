#include "NWNXLib.h"

void nwn_EffectSetNumIntegers(CGameEffect *eff, uint32_t num) {
    eff->eff_num_integers = num;
    eff->eff_integers = (int32_t*)realloc(eff->eff_integers, num*(sizeof(int32_t)));
}

uint32_t nwn_GetDurationType(CGameEffect *eff) {
    return eff->eff_dursubtype & 0x7;
}

uint32_t nwn_GetSubType(CGameEffect *eff) {
    return eff->eff_dursubtype & 0x18;
}

void nwn_SetAllInts(CGameEffect *eff, int32_t val) {
    size_t i = 0;
    for ( ; i < eff->eff_num_integers; ++i ) {
        eff->eff_integers[i] = val;
    }
}

void nwn_SetDurationType(CGameEffect *eff, uint32_t dur) {
    eff->eff_dursubtype = dur | nwn_GetSubType(eff);
}

void nwn_SetSubType(CGameEffect *eff, uint32_t value) {
    eff->eff_dursubtype = value | nwn_GetDurationType(eff);    
}
