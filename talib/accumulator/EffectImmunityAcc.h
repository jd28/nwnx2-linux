#ifndef _TALIB_ACCUMULATOR_IMMUNITY_H_
#define _TALIB_ACCUMULATOR_IMMUNITY_H_

#include "EffectAccumulator.h"

struct EffectImmunityAcc : public EffectAccumulator<int32_t, int32_t> {
    EffectImmunityAcc(CNWSCreature *cre, VersusInfo vs, int32_t immunity)
	: EffectAccumulator<int32_t, int32_t>(
	    cre, vs,
	    EFFECT_TRUETYPE_INVALIDEFFECT,
	    EFFECT_TRUETYPE_IMMUNITY,
	    false, false,
	    cre->cre_stats->cs_first_imm_eff),
	  immunity_(immunity) {}
    
    virtual bool is_valid(CGameEffect *eff);
    virtual int32_t get_max(int32_t a, int32_t b);
    virtual int32_t get_amount(CGameEffect *eff);
    virtual int32_t get_result();
    virtual int32_t get_subtype(CGameEffect *eff);

    int32_t immunity_;
};

#endif // _TALIB_ACCUMULATOR_IMMUNITY_H_
