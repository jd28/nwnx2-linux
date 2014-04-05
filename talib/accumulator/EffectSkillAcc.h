#ifndef _TALIB_ACCUMULATOR_SKILL_H_
#define _TALIB_ACCUMULATOR_SKILL_H_

#include "EffectAccumulator.h"

struct EffectSkillAcc : public EffectAccumulator<int32_t, int32_t> {
    EffectSkillAcc(CNWSCreature *cre, VersusInfo vs, int32_t type, uint8_t skill,
                   bool item_stack, bool spell_stack)
        : EffectAccumulator<int32_t, int32_t>(
            cre, vs, type, item_stack, spell_stack,
            cre->cre_stats->cs_first_skill_eff),
          skill_(skill) {}

    virtual int32_t get_amount(CGameEffect *eff);
    virtual int32_t get_max(int32_t a, int32_t b);
    virtual int32_t get_result();
    virtual int32_t get_subtype(CGameEffect *eff);
    virtual bool is_valid(CGameEffect *eff);

    uint8_t skill_;
};

#endif // _TALIB_ACCUMULATOR_SKILL_H_
