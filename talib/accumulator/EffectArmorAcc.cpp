#include "EffectArmorAcc.h"
#include <utility>

bool EffectArmorAcc::is_valid(CGameEffect *eff) {
    int32_t race      = eff->eff_integers[2];
    int32_t lawchaos  = eff->eff_integers[3];
    int32_t goodevil  = eff->eff_integers[4];
    int32_t dmg_flgs  = eff->eff_integers[5];

    // Non-versus effects are already cached on the Creature.
    if ( race == RACIAL_TYPE_INVALID &&
	 lawchaos == 0               &&
	 goodevil == 0 ) {
	return false;
    }

    if ( race == vs_.race         &&
	 lawchaos == vs_.lawchaos &&
	 goodevil == vs_.goodevil ) {
	return true;
    }
    else {
	return false;
    }
}

ArmorAmount EffectArmorAcc::get_max(ArmorAmount a, ArmorAmount b){
    return a.second > b.second ? a : b;
}

ArmorAmount EffectArmorAcc::get_amount(CGameEffect *eff){
    return std::make_pair(get_subtype(eff), eff->eff_integers[1]);
}

ArmorClass EffectArmorAcc::get_result(){
    ArmorClass p = { 0, 0, 0, 0, 0 };
    
    for ( size_t i = 0; i < bonus_idx; ++i ) {
	switch (bonus[i].first) {
	case AC_DODGE_BONUS:
	    result_.dodge += bonus[i].second;
	    break;
	case AC_NATURAL_BONUS:
	    result_.natural = std::max(bonus[i].second, result_.natural);
	    break;
	case AC_ARMOUR_ENCHANTMENT_BONUS:
	    result_.armor = std::max(bonus[i].second, result_.armor);
	    break;
	case AC_SHIELD_ENCHANTMENT_BONUS:
	    result_.shield = std::max(bonus[i].second, result_.shield);
	    break;
	case AC_DEFLECTION_BONUS:
	    result_.deflection = std::max(bonus[i].second, result_.deflection);
	    break;
	}
    }

    for ( size_t i = 0; i < penalty_idx; ++i ) {
	switch (penalty[i].first) {
	case AC_DODGE_BONUS:
	    p.dodge += penalty[i].second;
	    break;
	case AC_NATURAL_BONUS:
	    p.natural = std::max(penalty[i].second, p.natural);
	    break;
	case AC_ARMOUR_ENCHANTMENT_BONUS:
	    p.armor = std::max(penalty[i].second, p.armor);
	    break;
	case AC_SHIELD_ENCHANTMENT_BONUS:
	    p.shield = std::max(penalty[i].second, p.shield);
	    break;
	case AC_DEFLECTION_BONUS:
	    p.deflection = std::max(penalty[i].second, p.deflection);
	    break;
	}
    }

    result_.dodge = result_.dodge - p.dodge;
    result_.natural = result_.natural - p.natural;
    result_.armor = result_.armor - p.armor;
    result_.shield = result_.shield - p.shield;
    result_.deflection = result_.deflection - p.deflection;

    return result_;
}

int32_t EffectArmorAcc::get_subtype(CGameEffect *eff) {
    return eff->eff_integers[0];
}
