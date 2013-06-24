#ifndef _TALIB_EFFECTS_ITEMPROP_H_
#define _TALIB_EFFECTS_ITEMPROP_H_

extern "C" {
    
CGameEffect * ip_create(bool show_icon);
CGameEffect * ip_set_values(CGameEffect *eff, int type, int subtype, int cost,
			     int cost_val, int param1, int param1_val,
			     int uses_per_day, int chance);

CGameEffect * ip_ability(int32_t ability, int32_t bonus);

CGameEffect * ip_ac(int32_t bonus, uint8_t ac_type);

CGameEffect * ip_enhancement(int32_t bonus);

CGameEffect * ip_weight_increase(int32_t amount);
CGameEffect * ip_weight_reduction(int32_t amount);

CGameEffect * ip_feat(int32_t feat);

CGameEffect * ip_spell_cast(int32_t spell, int32_t uses);
CGameEffect * ip_spell_slot(int32_t cls, int32_t level);

CGameEffect * ip_damage(int32_t damage_type, int32_t damage);
CGameEffect * ip_damage_extra(int32_t damage_type, bool is_ranged);

CGameEffect * ip_damage_immunity(int32_t damage_type, int32_t amount);
CGameEffect * ip_damage_penalty(int32_t penalty);
CGameEffect * ip_damage_reduction(int32_t enhancement, int32_t soak);
CGameEffect * ip_damage_resistance(int32_t damage_type, int32_t amount);

CGameEffect * ip_damage_vulnerability(int32_t damage_type, int32_t amount);

CGameEffect * ip_darkvision();

CGameEffect * ip_skill(int32_t skill, int32_t amount);

CGameEffect * ip_container_reduced_weight(int32_t amount);

CGameEffect * ip_haste();
CGameEffect * ip_holy_avenger();
CGameEffect * ip_immunity_misc(int32_t immumity_type);
CGameEffect * ip_improved_evasion();

CGameEffect * ip_spell_resistance(int32_t amount);

CGameEffect * ip_save(int32_t save_type, int32_t amount);
CGameEffect * ip_save_vs(int32_t save_type, int32_t amount);

CGameEffect * ip_keen();

CGameEffect * ip_light(int32_t brightness, int32_t color);

CGameEffect * ip_mighty(int32_t modifier);

CGameEffect * ip_no_damage();

CGameEffect * ip_onhit(int32_t prop, int32_t dc, int32_t special);

CGameEffect * ip_regen(int32_t amount);

CGameEffect * ip_immunity_spell(int32_t spell);

CGameEffect * ip_immunity_spell_school(int32_t school);

CGameEffect * ip_thieves_tools(int32_t modifier);

CGameEffect * ip_attack(int32_t bonus);

CGameEffect * ip_unlimited_ammo(int32_t ammo);

CGameEffect * ip_use_align(int32_t align_group);
CGameEffect * ip_use_class(int32_t cls);
CGameEffect * ip_use_race(int32_t race);
CGameEffect * ip_use_salign(int32_t nAlignment);

CGameEffect * ip_regen_vampiric(int32_t amount);

CGameEffect * ip_trap(int32_t level, int32_t trap_type);

CGameEffect * ip_true_seeing();

CGameEffect * ip_onhit_monster(int32_t prop, int32_t special);

CGameEffect * ip_turn_resistance(int32_t modifier);

CGameEffect * ip_massive_critical(int32_t damage);

CGameEffect * ip_freedom();

CGameEffect * ip_monster_damage(int32_t damage);

CGameEffect * ip_immunity_spell_level(int32_t level);

CGameEffect * ip_special_walk(int32_t walk);

CGameEffect * ip_healers_kit(int32_t modifier);

CGameEffect * ip_material(int32_t material);

CGameEffect * ip_onhit_castspell(int32_t spell, int32_t level);

CGameEffect * ip_quality(int32_t quality);

CGameEffect * ip_additional(int32_t addition);

CGameEffect * ip_visual_effect(int32_t effect);
}
#endif // _TALIB_EFFECTS_ITEMPROP_H_
