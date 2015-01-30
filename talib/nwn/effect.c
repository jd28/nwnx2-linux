#include "NWNXLib.h"

void nwn_EffectSetNumIntegers(CGameEffect *eff, uint32_t num) {
    eff->eff_num_integers = num;
    eff->eff_integers = (int32_t*)realloc(eff->eff_integers, num*(sizeof(int32_t)));
    memset(eff->eff_integers, 0, num*(sizeof(int32_t));
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

CGameEffect * nwn_CreateEffect(int gen_id) {
    if ( CGameEffect__ctor == NULL ) { return NULL; }

    CGameEffect *eff = (CGameEffect *)malloc(sizeof(CGameEffect));
    CGameEffect__ctor(eff, gen_id);

    nwn_SetDurationType(eff, DURATION_TYPE_PERMANENT);
    eff->eff_creator = (*NWN_VirtualMachine)->vm_implementer->vmc_object_id;

    return eff;
}
