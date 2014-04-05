#ifndef _TALIB_ACCUMULATOR_ABILITY_H_
#define _TALIB_ACCUMULATOR_ABILITY_H_

#include "EffectAccumulator.h"

struct EffectAbilityAcc : public EffectAccumulator<int32_t, int32_t> {
    EffectAbilityAcc(CNWSCreature *cre, int32_t type, int32_t ability,
                     bool item_stack, bool spell_stack)
        : EffectAccumulator<int32_t, int32_t>(
            cre, VersusInfo(NULL),
            type, item_stack, spell_stack,
            cre->cre_stats->cs_first_ability_eff)
        , ability_(ability) {}

    virtual bool is_valid(CGameEffect *eff);
    virtual int32_t get_max(int32_t a, int32_t b);
    virtual int32_t get_amount(CGameEffect *eff);
    virtual int32_t get_result();
    virtual int32_t get_subtype(CGameEffect *eff);

    int32_t ability_;
};

#endif // _TALIB_ACCUMULATOR_ABILITY_H_
