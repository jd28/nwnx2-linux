#include "EffectSkillAcc.h"

bool EffectSkillAcc::is_valid(CGameEffect *eff) {
    return skill_ == get_subtype(eff);
}

int32_t EffectSkillAcc::get_max(int32_t a, int32_t b){
    return std::max(a, b);
}

int32_t EffectSkillAcc::get_amount(CGameEffect *eff){
    return eff->eff_integers[1];
}

int32_t EffectSkillAcc::get_result(){
    if (!accumulated_) accumulate();
    if (resulted_) return result_;

    for (uint32_t i = 0; i < idx; i++)
        result_ += amounts[i];

    resulted_ = true;
    return result_;
}

int32_t EffectSkillAcc::get_subtype(CGameEffect *eff) {
    return eff->eff_integers[0];
}
