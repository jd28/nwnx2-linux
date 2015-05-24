#ifndef TALIB_EFFECT_H
#define TALIB_EFFECT_H

extern "C" {

void nwn_EffectSetNumIntegers(CGameEffect *eff, uint32_t num);
uint32_t nwn_GetDurationType(CGameEffect *eff);
uint32_t nwn_GetSubType(CGameEffect *eff);
void nwn_SetAllInts(CGameEffect *eff, int32_t val);
void nwn_SetDurationType(CGameEffect *eff, uint32_t dur);
void nwn_SetSubType(CGameEffect *eff, uint32_t value);
CGameEffect * nwn_CreateEffect(int gen_id);

}

#endif // TALIB_EFFECT_H
