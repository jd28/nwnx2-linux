#include "NWNXLib.h"
#include "creation.h"
#include "../nwn/effect.h"
#include "../util/math.h"

CGameEffect * ip_create(bool show_icon) {
    CGameEffect * eff = nwn_CreateEffect(show_icon);
    CGameEffect__SetNumIntegers(eff, 9);
    eff->eff_type = EFFECT_TRUETYPE_ITEMPROPERTY;
    nwn_SetAllInts(eff, -1);
    nwn_SetSubType(eff, 0);
    nwn_SetDurationType(eff, DURATION_TYPE_PERMANENT);
   
    return eff;
}

// Sets the item property effect values directly.
CGameEffect * ip_set_values(CGameEffect *eff, int type, int subtype, int cost,
                            int cost_val, int param1, int param1_val,
                            int uses_per_day, int chance) {
    
    eff->eff_integers[0] = type;
    eff->eff_integers[1] = subtype;
    eff->eff_integers[2] = cost;
    eff->eff_integers[3] = cost_val;
    eff->eff_integers[4] = param1;
    eff->eff_integers[5] = param1_val;
    eff->eff_integers[6] = uses_per_day;
    eff->eff_integers[7] = chance; // Chance
    eff->eff_integers[8] = 1; // Useable

    return eff;
}

// @param
// @param
CGameEffect * ip_ability(int32_t ability, int32_t bonus) {
    return ( bonus < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_ABILITY_SCORE, ability, 21, CLAMP<int32_t>(-bonus, 1, 12), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_ABILITY_BONUS, ability, 1, CLAMP<int32_t>(bonus, 1, 12), -1, -1, 1, 100);
}

//-
// @param
// @param
CGameEffect * ip_ac(int32_t bonus, uint8_t ac_type) {
    return ( bonus < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_AC, ac_type, 20, CLAMP<int32_t>(-bonus, 1, 20), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_AC_BONUS, ac_type, 2, CLAMP<int32_t>(bonus, 1, 20), -1, -1, 1, 100);
}

CGameEffect * ip_arcane_spell_failure(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_ARCANE_SPELL_FAILURE, -1, 27, amount, -1, -1, 1, 100);
}

//- Item Property Enhancement Bonus
// @param bonus If greater than 0 enhancment bonus, else penalty
CGameEffect * ip_enhancement(int32_t bonus) {   
    return ( bonus < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_ENHANCEMENT_MODIFIER, -1, 20, CLAMP<int32_t>(-bonus, 1, 20), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_ENHANCEMENT_BONUS, -1, 2, CLAMP<int32_t>(bonus, 1, 20), -1, -1, 1, 100);
}

//- Item Property Weight Increase
// @param amount IP_CONST_WEIGHTINCREASE_*
CGameEffect * ip_weight_increase(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_WEIGHT_INCREASE, -1, 0, -1, 11, amount, 1, 100);
}

//- Item Property Weight Reuction
// @param amount IP_CONST_REDUCEDWEIGHT_*
CGameEffect * ip_weight_reduction(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_BASE_ITEM_WEIGHT_REDUCTION, -1, 10, amount, -1, -1, 1, 100);
}

//- Item Property Bonus Feat
// @param feat IP_CONST_FEAT_*
CGameEffect * ip_feat(int32_t feat) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_BONUS_FEAT, -1, 0, feat, -1, -1, 1, 100);
}

//- Creates a "bonus spell of a specified level" itemproperty.
// @param class IP_CONST_CLASS_*
// @param level [0, 9]
CGameEffect * ip_spell_slot(int32_t cls, int32_t level) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_BONUS_SPELL_SLOT_OF_LEVEL_N, cls, 13, level, -1, -1, 1, 100);
}

//- Creates a "cast spell" itemproperty.
// @param spell IP_CONST_CASTSPELL_*
// @param uses IP_CONST_CASTSPELL_NUMUSES_*
CGameEffect * ip_spell_cast(int32_t spell, int32_t uses) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_CAST_SPELL, spell, 3, uses, -1, -1, 1, 100);
}

//- Creates a damage bonus itemproperty.
// @param damage_type IP_CONST_DAMAGETYPE_*
// @param damage IP_CONST_DAMAGEBONUS_*
CGameEffect * ip_damage(int32_t damage_type, int32_t damage) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_DAMAGE_BONUS, damage_type, 4, damage, -1, -1, 1, 100);
}

//- Creates a damage immunity itemproperty.
// @param damage_type IP_CONST_DAMAGETYPE_*
// @param amount 
CGameEffect * ip_damage_immunity(int32_t damage_type, int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_IMMUNITY_DAMAGE_TYPE, damage_type, 5, amount, -1, -1, 1, 100);
}

//- Creatses a damage penalty itemproperty.
// @param penalty [1,5]
CGameEffect * ip_damage_penalty(int32_t penalty) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_DAMAGE, -1, 20, penalty, -1, -1, 1, 100);
}

//- Creates a damage reduction itemproperty.
// @param enhancement IP_CONST_DAMAGEREDUCTION_*
// @param soak IP_CONST_DAMAGESOAK_*
CGameEffect * ip_damage_reduction(int32_t enhancement, int32_t soak) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_DAMAGE_REDUCTION, enhancement, 6, soak, -1, -1, 1, 100);
}

//- Creates damage resistance item property.
// @param damage_type IP_CONST_DAMAGETYPE_*
// @param amount IP_CONST_DAMAGERESIST_*
CGameEffect * ip_damage_resistance(int32_t damage_type, int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_DAMAGE_RESISTANCE, damage_type, 7, amount, -1, -1, 1, 100);
}

//- Creates damage vulnerability item property.
// @param damage_type IP_CONST_DAMAGETYPE_*
// @param amount IP_CONST_DAMAGEVULNERABILITY_*
CGameEffect * ip_damage_vulnerability(int32_t damage_type, int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_DAMAGE_VULNERABILITY, damage_type, 22, amount, -1, -1, 1, 100);
}

//- Creates Darkvision Item Property
CGameEffect * ip_darkvision() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_DARKVISION, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates skill modifier item property
// @param skill SKILL_*
// @param amount [1, 50] or [-10, -1]
CGameEffect * ip_skill(int32_t skill, int32_t amount) {
    return ( amount < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_SKILL_MODIFIER, skill, 21, CLAMP<int32_t>(-amount, 1, 10), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_SKILL_BONUS, skill, 25, CLAMP<int32_t>(amount, 1, 50), -1, -1, 1, 100);
}

//- Create a "reduced weight container" itemproperty.
// @param container_type IP_CONST_CONTAINERWEIGHTRED_*
CGameEffect * ip_container_reduced_weight(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_ENHANCED_CONTAINER_REDUCED_WEIGHT, -1, 15, amount, -1, -1, 1, 100);
}

//- Creates an "extra damage type" item property.
// @param damage_type IP_CONST_DAMAGETYPE_*
// @param is_ranged ExtraRangedDamge if true, melee if false (Default: false)
CGameEffect * ip_damage_extra(int32_t damage_type, bool is_ranged = false) {
    return is_ranged
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_EXTRA_RANGED_DAMAGE_TYPE, damage_type, 0, -1, -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_EXTRA_MELEE_DAMAGE_TYPE, damage_type, 0, -1, -1, -1, 1, 100);
}

//- Creates haste item property.
CGameEffect * ip_haste() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_HASTE, 0, -1, -1, -1, -1, 1, 100);
}

//- Creates Holy Avenger item propety.
CGameEffect * ip_holy_avenger() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_HOLY_AVENGER, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates immunity item property
// @param immumity_type IP_CONST_IMMUNITYMISC_*
CGameEffect * ip_immunity_misc(int32_t immumity_type) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_IMMUNITY_MISCELLANEOUS, immumity_type, 0, -1, -1, -1, 1, 100);
}

//- Creates Improved evasion item property.
CGameEffect * ip_improved_evasion() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_IMPROVED_EVASION, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates a spell resistince item property
// @param amount IP_CONST_SPELLRESISTANCEBONUS_*
CGameEffect * ip_spell_resistance(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_SPELL_RESISTANCE, -1, 11, amount, -1, -1, 1, 100);
}

//- Creates saving throw bonus vs item property
// @param save_type IP_CONST_SAVEVS_*
// @param amount [1,20] or [-20, -1]
CGameEffect * ip_save_vs(int32_t save_type, int32_t amount) {
    return ( amount < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_SAVING_THROWS, save_type, 20, CLAMP<int32_t>(-amount, 1, 20), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_SAVING_THROW_BONUS, save_type, 2, CLAMP<int32_t>(amount, 1, 20), -1, -1, 1, 100);
}

//- Creates saving throw bonus item property
// @param save_type IP_CONST_SAVEBASETYPE_*
// @param amount [1,20] or [-20, -1]
CGameEffect * ip_save(int32_t save_type, int32_t amount) {
    return ( amount < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_SAVING_THROWS_SPECIFIC, save_type, 20, CLAMP<int32_t>(-amount, 1, 10), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_SAVING_THROW_BONUS_SPECIFIC, save_type, 2, CLAMP<int32_t>(amount, 1, 50), -1, -1, 1, 100);
}

//- Creates keen item property
CGameEffect * ip_keen() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_KEEN, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates a light item property.
// @param brightness IP_CONST_LIGHTBRIGHTNESS_*
// @param color IP_CONST_LIGHTCOLOR_*
CGameEffect * ip_light(int32_t brightness, int32_t color) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_LIGHT, -1, 18, brightness, 9, color, 1, 100);
}

//- Creates a mighty item property.
// @param modifier [1,20]
CGameEffect * ip_mighty(int32_t modifier) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_MIGHTY, -1, 2, CLAMP<int32_t>(modifier, 1, 20), -1, -1, 1, 100);
}

//- Creates no damage item property
CGameEffect * ip_no_damage() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_NO_DAMAGE, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates an OnHit itemproperty.
// @param prop IP_CONST_ONHIT_*
// @param dc IP_CONST_ONHIT_SAVEDC_*
// @param special Meaning varies with type. (Default: 0)
CGameEffect * ip_onhit(int32_t prop, int32_t dc, int32_t special) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_ON_HIT_PROPERTIES, prop, 24, dc, 0, special, 1, 100);
}

//- Creates a regeneration item property.
// @param amount [1, 20]
CGameEffect * ip_regen(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_REGENERATION, -1, 2, CLAMP<int32_t>(amount, 1, 20), -1, -1, 1, 100);
}

//- Creates an "immunity to specific spell" itemproperty.
// @param spell IP_CONST_IMMUNITYSPELL_*
CGameEffect * ip_immunity_spell(int32_t spell) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_IMMUNITY_SPECIFIC_SPELL, -1, 16, spell, -1, -1, 1, 100);
}

//- Creates an "immunity against spell school" itemproperty.
// @param school IP_CONST_SPELLSCHOOL_*
CGameEffect * ip_immunity_spell_school(int32_t school) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_IMMUNITY_SPECIFIC_SPELL, school, 0, -1, -1, -1, 1, 100);
}

//- Creates a thieves tool item property
// @param modifier [1, 12]
CGameEffect * ip_thieves_tools(int32_t modifier) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_THIEVES_TOOLS, -1, 25, CLAMP<int32_t>(modifier, 1, 12), -1, -1, 1, 100);
}

//- Creatures attack modifier item property
// @param bonus [1,20] or [-5, -1]
CGameEffect * ip_attack(int32_t bonus) {
    return ( bonus < 0 )
        ? ip_set_values(ip_create(false), ITEM_PROPERTY_DECREASED_ATTACK_MODIFIER, -1, 25, CLAMP<int32_t>(bonus, 1, 5), -1, -1, 1, 100)
        : ip_set_values(ip_create(false), ITEM_PROPERTY_ATTACK_BONUS, -1, 20, CLAMP<int32_t>(bonus, 1, 20), -1, -1, 1, 100);
}

//- Creates an unlimited ammo itemproperty.
// @param ammo IP_CONST_UNLIMITEDAMMO_* (Default: )
CGameEffect * ip_unlimited_ammo(int32_t ammo = IP_CONST_UNLIMITEDAMMO_BASIC) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_UNLIMITED_AMMUNITION, ammo, 14, -1, -1, -1, 1, 100);
}

CGameEffect * ip_use_align(int32_t align_group) { return NULL; }

//- Creates a class use limitation item property
// @param class IP_CONST_CLASS_*
CGameEffect * ip_use_class(int32_t cls) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_USE_LIMITATION_CLASS, cls, 0, -1, -1, -1, 1, 100);
}

//- Creates a race use limitation item property
// @param race Racial type
CGameEffect * ip_use_race(int32_t race) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_USE_LIMITATION_RACIAL_TYPE, race, 0, -1, -1, -1, 1, 100);
}

CGameEffect * ip_use_salign(int32_t nAlignment) { return NULL; }

//- Creates vampiric regeneration effect.
// @param amount [1,20]
CGameEffect * ip_regen_vampiric(int32_t amount) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_REGENERATION_VAMPIRIC, -1, 2, CLAMP<int32_t>(amount, 1, 20), -1, -1, 1, 100);
}

//- Creates a trap item property
// @param level IP_CONST_TRAPSTRENGTH_*
// @param trap_type IP_CONST_TRAPTYPE_*
CGameEffect * ip_trap(int32_t level, int32_t trap_type) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_TRAP, trap_type, 17, level, -1, -1, 1, 100);
}

//- Creates true seeing item property
CGameEffect * ip_true_seeing() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_TRUE_SEEING, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates on monster hit item property.
// NOTE: Item property is bugged.  See NWN Lexicon.
// @param prop IP_CONST_ONMONSTERHIT_*
// @param special ???
CGameEffect * ip_onhit_monster(int32_t prop, int32_t special) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_ON_MONSTER_HIT, prop, 0, special, -1, -1, 1, 100);
}

//- Creates a turn resistance item property.
// @param modifier [1, 50]
CGameEffect * ip_turn_resistance(int32_t modifier) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_TURN_RESISTANCE, -1, 25, CLAMP<int32_t>(modifier, 1, 50), -1, -1, 1, 100);
}

//- Creates a massive criticals item property.
// @param damage IP_CONST_DAMAGEBONUS_*
CGameEffect * ip_massive_critical(int32_t damage) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_MASSIVE_CRITICALS, -1, 4, damage, -1, -1, 1, 100);
}

//- Creates a free action (freedom of movement) itemproperty.
CGameEffect * ip_freedom() {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_FREEDOM_OF_MOVEMENT, -1, 0, -1, -1, -1, 1, 100);
}

//- Creates Monster Damage effect.
// @param damage IP_CONST_MONSTERDAMAGE_*
CGameEffect * ip_monster_damage(int32_t damage) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_MONSTER_DAMAGE, -1, 19, damage, -1, -1, 1, 100);
}

//- Create an "immunity to spell level" item property.
// @param level Spell level [1,9]
CGameEffect * ip_immunity_spell_level(int32_t level) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_IMMUNITY_SPELLS_BY_LEVEL, -1, 23, level, -1, -1, 1, 100);
}

//- Creates a special walk itemproperty.
// @param walk Only 0 is a valid argument (Default: 0)
CGameEffect * ip_special_walk(int32_t walk = 0) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_SPECIAL_WALK, walk, -1, -1, -1, -1, 1, 100);
}

//- Creates a healers' kit item property.
// @param modifier [1,12]
CGameEffect * ip_healers_kit(int32_t modifier) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_HEALERS_KIT, -1, 25, modifier, -1, -1, 1, 100);
}

//- Creates material item property
// @param material The material type should be [0, 77] based on 
//    iprp_matcost.2da.
CGameEffect * ip_material(int32_t material) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_MATERIAL, -1, 28, material, -1, -1, 1, 100);
}

//- Creates an "on hit cast spell" item property.
// @param spell IP_CONST_ONHIT_CASTSPELL_*
// @param level Level spell is cast at.
CGameEffect * ip_onhit_castspell(int32_t spell, int32_t level) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_ONHITCASTSPELL, spell, 26, level, -1, -1, 1, 100);
}

//- Creates quality item property
// @param quality IP_CONST_QUALITY_*
CGameEffect * ip_quality(int32_t quality) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_QUALITY, -1, 29, quality, -1, -1, 1, 100);
}

//- Creates additional item property
// @param addition IP_CONST_ADDITIONAL_* 
CGameEffect * ip_additional(int32_t addition) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_ADDITIONAL, -1, 30, addition, -1, -1, 1, 100);
}

//- Creates a visual effect item property
// @param effect ITEM_VISUAL_*
CGameEffect * ip_visual_effect(int32_t effect) {
    return ip_set_values(ip_create(false), ITEM_PROPERTY_VISUALEFFECT, effect, -1, -1, -1, -1, 1, 100);
}
