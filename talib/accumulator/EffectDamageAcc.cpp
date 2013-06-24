#include "EffectDamageAcc.h"
#include <utility>

bool EffectDamageAcc::is_valid(CGameEffect *eff) {
    int32_t atk_type  = eff->eff_integers[5];
    int32_t race      = eff->eff_integers[2];
    int32_t lawchaos  = eff->eff_integers[3];
    int32_t goodevil  = eff->eff_integers[4];
    
    return ( ( atk_type == ATTACK_TYPE_MISC || atk_type == attack_type_ ) &&
	     ( lawchaos == 0 || lawchaos != vs_.lawchaos )                &&
	     ( race == 0 || race == vs_.race )                            &&
	     ( goodevil == 0 || goodevil == vs_.goodevil) );
}

DamageAmount EffectDamageAcc::get_max(DamageAmount a, DamageAmount b){
    int32_t total1 = a.roll.dice * a.roll.sides + a.roll.bonus;
    int32_t total2 = b.roll.dice * b.roll.sides + b.roll.bonus;

    return total1 > total2 ? a : b;
}

DamageAmount EffectDamageAcc::get_amount(CGameEffect *eff){
    int32_t dmg_type = eff->eff_integers[1];
    // TODO IP_CONST -> damage index
    return DamageAmount(dmg_type, DiceRoll(), false);
}

DamageResult EffectDamageAcc::get_result(){
    
    for ( size_t i = 0; bonus_idx; ++i ) {
	result_.bonus[bonus[i].type].push_back(bonus[i].roll);
    }

    for ( size_t i = 0; penalty_idx; ++i ) {
	result_.penalty[penalty[i].type].push_back(penalty[i].roll);
    }

    return result_;
}

int32_t EffectDamageAcc::get_subtype(CGameEffect *eff){
    return eff->eff_integers[1];
}
