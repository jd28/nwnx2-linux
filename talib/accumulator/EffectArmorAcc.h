#ifndef _TALIB_ACCUMULATOR_ARMOR_H_
#define _TALIB_ACCUMULATOR_ARMOR_H_

#include "talib/custom/armor_class.h"
#include "EffectAccumulator.h"

struct EffectArmorAcc : public EffectAccumulator<ArmorAmount, ArmorClass> {
    EffectArmorAcc(CNWSCreature *cre, VersusInfo vs)
	: EffectAccumulator<ArmorAmount, ArmorClass>(
	    cre, vs,
	    EFFECT_TRUETYPE_AC_DECREASE,
	    EFFECT_TRUETYPE_AC_INCREASE,
	    false, false,
	    cre->cre_stats->cs_first_ac_eff) {

	result_ = { 0, 0, 0, 0, 0 };
    }

    virtual bool is_valid(CGameEffect *eff);
    virtual ArmorAmount get_max(ArmorAmount a, ArmorAmount b);
    virtual ArmorAmount get_amount(CGameEffect *eff);
    virtual ArmorClass get_result();
    virtual int32_t get_subtype(CGameEffect *eff);
};

#endif // _TALIB_ACCUMULATOR_ARMOR_H_
