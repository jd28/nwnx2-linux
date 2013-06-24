#ifndef _TALIB_ACCUMULATOR_DAMAGE_H_
#define _TALIB_ACCUMULATOR_DAMAGE_H_

#include "EffectAccumulator.h"
#include "../custom/damage.h"

struct EffectDamageAcc : public EffectAccumulator<DamageAmount, DamageResult> {
    EffectDamageAcc(CNWSCreature *cre, VersusInfo vs, int32_t attack_type)
	: EffectAccumulator<DamageAmount, DamageResult>(
	    cre, vs,
	    EFFECT_TRUETYPE_DAMAGE_DECREASE,
	    EFFECT_TRUETYPE_DAMAGE_INCREASE,
	    false, false,
	    cre->cre_stats->cs_first_damage_eff),
	  attack_type_(attack_type) {}
    
    virtual bool is_valid(CGameEffect *eff);
    virtual DamageAmount get_max(DamageAmount a, DamageAmount b);
    virtual DamageAmount get_amount(CGameEffect *eff);
    virtual DamageResult get_result();
    virtual int32_t get_subtype(CGameEffect *eff);

    int32_t attack_type_;
};

#endif // _TALIB_ACCUMULATOR_DAMAGE_H_
