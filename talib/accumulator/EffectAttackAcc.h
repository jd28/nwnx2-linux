#ifndef _TALIB_ACCUMULATOR_ATTACK_H_
#define _TALIB_ACCUMULATOR_ATTACK_H_

#include "EffectAccumulator.h"

struct EffectAttackAcc : public EffectAccumulator<int32_t, int32_t> {
    EffectAttackAcc(CNWSCreature *cre, VersusInfo vs, int32_t type)
	: EffectAccumulator<int32_t, int32_t>(
	    cre, vs,
	    EFFECT_TRUETYPE_ATTACK_DECREASE,
	    EFFECT_TRUETYPE_ATTACK_INCREASE,
	    false, false,
	    cre->cre_stats->cs_first_ab_effect),
	  attack_type(type) { }
    
    virtual bool is_valid(CGameEffect *eff);
    virtual int32_t get_max(int32_t a, int32_t b);
    virtual int32_t get_amount(CGameEffect *eff);
    virtual int32_t get_result();
    virtual int32_t get_subtype(CGameEffect *eff);

    int32_t attack_type;
};

#endif // _TALIB_ACCUMULATOR_ATTACK_H_