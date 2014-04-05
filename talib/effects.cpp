#include "accumulator/all.h"

ArmorClass GetArmorClassEffects(CNWSCreature *cre, VersuInfo vs,
                                bool penalty, bool item_stack,
                                bool spell_stack) {
    if (!use_versus) {
        ArmorClass p = { 0, 0, 0, 0, 0 };
        return p;
    }
    int32_t type = penalty ? EFFECT_TRUETYPE_AC_DECREASE : EFFECT_TRUETYPE_AC_INCREASE;
    auto acc = EffectArmorAcc(cre, vs, type, use_vs, item_stack, spell_stack);
    acc.accumulate();
    return acc.get_result();
}

int32_t GetAttackEffects(CNWSCreature *cre, VersuInfo vs,
                         int32_t eff_type, int32_t type,
                         bool item_stack, bool spell_stack) {
    auto acc = EffectAttackAcc(cre, vs, eff_type, type, use_vs, item_stack, spell_stack);
    acc.accumulate();
    return acc.get_result();
}

int32_t GetAbilityEffects(CNWSCreature *cre, int32_t type, int32_t ability,
                          bool item_stack, bool spell_stack) {
    auto acc = EffectArmorAcc(cre, type, ability, item_stack, spell_stack);
    acc.accumulate();
    return acc.get_result();
}

int32_t GetImmunityEffects(CNWSCreature *cre, VersusInfo vs, int32_t immunity,
                           bool item_stack, bool spell_stack) {
    auto acc = EffectImmunityAcc(cre, vs, immunity, item_stack, spell_stack);
    acc.accumulate();
    return acc.get_result();
}

int32_t GetSaveEffects(CNWSCreature *cre, VersusInfo vs, int32_t type,
                       int32_t save, int32_t save_vs, bool item_stack,
                       bool spell_stack) {
    auto acc = EffectSaveAcc(cre, vs, type, save, save_vs, item_stack, spell_stack);
    acc.accumulate();
    return acc.get_result();
}

int32_t GetSkillEffect(CNWSCreature *cre, VersusInfo vs, int32_t type, uint8_t skill,
                       bool item_stack, bool spell_stack) {
    auto acc = EffectSkillAcc(cre, vs, type, skill, item_stack, spell_stack);
    acc.accumulate();
    return acc.get_result();
}
