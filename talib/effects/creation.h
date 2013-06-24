#ifndef TALIB_EFFECTS_CREATION_H
#define TALIB_EFFECTS_CREATION_H

#include "NWNXLib.h"

extern "C" {

// Creation functions
CGameEffect * nwn_CreateEffect(int show_icon);
    
CGameEffect * effect_ability(int32_t ability, int32_t amount);
CGameEffect * effect_ac(int32_t amount, int32_t modifier_type, int32_t damage_type);

CGameEffect * effect_appear(bool animation);
CGameEffect * effect_aoe(int32_t aoe, const char * enter, const char * heartbeat, const char * exit);

CGameEffect * effect_attack(int32_t amount, int32_t modifier_type);

CGameEffect * effect_beam(int32_t beam, int32_t creator, int32_t bodypart, int32_t miss_effect);
CGameEffect * effect_blindness();
CGameEffect * effect_feat (int32_t feat);
CGameEffect * effect_charmed();
CGameEffect * effect_concealment(int32_t amount, int32_t miss_type);
CGameEffect * effect_confused();
CGameEffect * effect_curse(int32_t str = 1, int32_t dex = 1, int32_t con = 1,
			   int32_t intg = 1, int32_t wis = 1, int32_t cha = 1);

CGameEffect * effect_cutscene_dominated();
CGameEffect * effect_cutscene_ghost();
CGameEffect * effect_cutscene_immobilize();
CGameEffect * effect_cutscene_paralyze();

CGameEffect * effect_damage(int32_t amount, int32_t damage_type, int32_t power);
CGameEffect * effect_damage_decrease(int32_t amount, int32_t damage_type, int32_t attack_type);
CGameEffect * effect_damage_increase(int32_t amount, int32_t damage_type, int32_t attack_type);

/*
CGameEffect * effect_DamageRangeDecrease(start, stop, damage_type, attack_type);
CGameEffect * effect_DamageRangeIncrease(start, stop, damage_type, attack_type);
*/

CGameEffect * effect_damage_immunity(int32_t damage_type, int32_t percent);
CGameEffect * effect_damage_reduction(int32_t amount, int32_t power, int32_t limit);
CGameEffect * effect_damage_resistance(int32_t damage_type, int32_t amount, int32_t limit);
CGameEffect * effect_damage_shield(int32_t amount, int32_t random, int32_t damage_type);

CGameEffect * effect_darkness();
CGameEffect * effect_dazed();
CGameEffect * effect_deaf();
CGameEffect * effect_death(bool spectacular, bool feedback);
CGameEffect * effect_disappear(bool animation);
CGameEffect * effect_disappear_appear(CScriptLocation location, bool animation = true);

CGameEffect * effect_disarm();
CGameEffect * effect_disease(int32_t disease);

CGameEffect * effect_dispel_all(int32_t diseasecaster_level);
CGameEffect * effect_dispel_best(int32_t diseasecaster_level);

CGameEffect * effect_dominated();
CGameEffect * effect_entangle();
CGameEffect * effect_ethereal();
CGameEffect * effect_frightened();
CGameEffect * effect_haste();

CGameEffect * effect_heal(int32_t amount);

CGameEffect * effect_hp_change_when_dying(float hitpoint_change);

/*
CGameEffect * effect_hp_decrease(int32_t amount);
CGameEffect * effect_hp_increase(int32_t amount);
*/

CGameEffect * effect_icon(int32_t icon);

CGameEffect * effect_immunity(int32_t immunity, int32_t percent);

CGameEffect * effect_invisibility(int32_t type);

CGameEffect * effect_knockdown();

CGameEffect * effect_link(CGameEffect *child, CGameEffect *parent);

CGameEffect * effect_miss_chance(int32_t amount, int32_t miss_type);

CGameEffect * effect_additional_attacks(int32_t amount);
CGameEffect * effect_move_speed(int32_t amount);
CGameEffect * effect_negative_level(int32_t amount, bool hp_bonus);

CGameEffect * effect_paralyze();
CGameEffect * effect_petrify();
CGameEffect * effect_poison(int32_t type);

CGameEffect * effect_polymorph(int32_t polymorph, bool locked);

CGameEffect * effect_regen(int32_t amount, float interval);

CGameEffect * effect_resurrection();
CGameEffect * effect_sanctuary(int32_t dc);

CGameEffect * effect_save(int32_t save, int32_t amount, int32_t save_type);

CGameEffect * effect_see_invisible();
CGameEffect * effect_silence();
CGameEffect * effect_skill(int32_t skill, int32_t amount);
CGameEffect * effect_sleep();
CGameEffect * effect_slow();
CGameEffect * effect_spell_failure(int32_t percent, int32_t spell_school);

CGameEffect * effect_spell_immunity(int32_t spell);

CGameEffect * effect_spell_absorbtion(int32_t max_level, int32_t max_spells, int32_t school);
CGameEffect * effect_spell_resistance(int32_t amount);
CGameEffect * effect_stunned();

CGameEffect * effect_summon(const char * resref, int32_t vfx, float delay, bool appear);
CGameEffect * effect_swarm(bool looping, const char * resref1, const char * resref2, const char * resref3, const char * resref4);

CGameEffect * effect_hp_temporary(int32_t amount);
CGameEffect * effect_time_stop();
CGameEffect * effect_true_seeing();
CGameEffect * effect_turned();

CGameEffect * effect_turn_resistance(int32_t amount);
CGameEffect * effect_ultravision();
CGameEffect * effect_visual(int32_t id, bool miss);
CGameEffect * effect_wounding (int32_t amount);

}
#endif // _TALIB_EFFECTS_CREATION_H_
