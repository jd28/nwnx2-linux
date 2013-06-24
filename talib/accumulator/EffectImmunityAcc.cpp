#include "EffectImmunityAcc.h"

#ifdef TALIB_IGNORE_VERUS_EFFECTS    
bool EffectImmunityAcc::is_valid(CGameEffect *eff) {
    return immunity_ == get_subtype(eff);
}
#else
bool EffectImmunityAcc::is_valid(CGameEffect *eff) {
    int32_t race      = eff->eff_integers[1];
    int32_t lawchaos  = eff->eff_integers[2];
    int32_t goodevil  = eff->eff_integers[3];
    
    return ( immunity_ == get_subtype(eff)                 &&
	     ( lawchaos == 0 || lawchaos != vs_.lawchaos ) &&
	     ( race == 0 || race == vs_.race )             &&
	     ( goodevil == 0 || goodevil == vs_.goodevil) );
}
#endif

int32_t EffectImmunityAcc::get_max(int32_t a, int32_t b){
    return std::max(a, b);
}
    
int32_t EffectImmunityAcc::get_amount(CGameEffect *eff){
    int32_t amount = eff->eff_integers[4];
    // Assume that an default EffectImmunity applied
    // means 100% immunity.
    if ( amount == 0 ) { amount = 100; }
    return amount;
}

int32_t EffectImmunityAcc::get_result(){
    if (!accumulated_) accumulate();
    if (resulted_) return result_;
	    
    int32_t total_bonus = 0;
    int32_t total_penalty = 0;

    for (uint32_t i = 0; i < bonus_idx; i++)
	total_bonus += bonus[i];

    for (uint32_t i = 0; i < penalty_idx; i++)
	total_penalty += penalty[i];

    resulted_ = true;
    result_ = CLAMP<int32_t>(total_bonus - total_penalty, 0, 100);
    return result_;
}

int32_t EffectImmunityAcc::get_subtype(CGameEffect *eff) {
    return eff->eff_integers[0];
}
