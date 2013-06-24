#include "EffectAbilityAcc.h"

bool EffectAbilityAcc::is_valid(CGameEffect *eff) {
    return ability_ == get_subtype(eff);
}

int32_t EffectAbilityAcc::get_max(int32_t a, int32_t b){
    return std::max(a, b);
}

int32_t EffectAbilityAcc::get_amount(CGameEffect *eff){
    return eff->eff_integers[1];
}

int32_t EffectAbilityAcc::get_result(){
    if (!accumulated_) accumulate();
    if (resulted_) return result_;
	    
    int32_t total_bonus = 0;
    int32_t total_penalty = 0;

    for (size_t i = 0; i < bonus_idx; i++)
	total_bonus += bonus[i];

    for (size_t i = 0; i < penalty_idx; i++)
	total_penalty += penalty[i];

    resulted_ = true;
    result_ = CLAMP<int32_t>(total_bonus - total_penalty, -20, 20);
    return total_bonus - total_penalty;
}

int32_t EffectAbilityAcc::get_subtype(CGameEffect *eff) {
    return eff->eff_integers[0];
}
