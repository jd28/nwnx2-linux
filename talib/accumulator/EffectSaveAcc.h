#ifndef _TALIB_ACCUMULATOR_SAVE_H_
#define _TALIB_ACCUMULATOR_SAVE_H_

#include "EffectAccumulator.h"

struct EffectSaveAcc : public EffectAccumulator<int32_t, int32_t> {
    EffectSaveAcc(CNWSCreature *cre, VersusInfo vs, int32_t type,
                  int32_t save, int32_t save_vs, bool item_stack,
                  bool spell_stack)
        : EffectAccumulator<int32_t, int32_t>(
            cre, vs, type, item_stack, spell_stack,
            cre->cre_stats->cs_first_save_eff),
          save_(save),
          save_vs_(save_vs) {}

    virtual bool is_valid(CGameEffect *eff);
    virtual int32_t get_max(int32_t a, int32_t b);
    virtual int32_t get_amount(CGameEffect *eff);
    virtual int32_t get_result();
    virtual int32_t get_subtype(CGameEffect *eff);

    int32_t save_;
    int32_t save_vs_;
};

#endif // _TALIB_ACCUMULATOR_SAVE_H_
