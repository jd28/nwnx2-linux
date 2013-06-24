#include "creation.h"

extern "C" {
#include "../effect.h"
}

CGameEffect * nwn_CreateEffect(int show_icon) {
    if ( CGameEffect__ctor == NULL ) { return NULL; }

    CGameEffect *eff = (CGameEffect *)malloc(sizeof(CGameEffect));
    CGameEffect__ctor(eff, show_icon);
    
    nwn_SetDurationType(eff, DURATION_TYPE_PERMANENT);
    eff->eff_creator = (*NWN_VirtualMachine)->vm_implementer->vmc_object_id;

    return eff;
}
    
static CGameEffect * effect_basic(int32_t type) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = type;

    return eff;
}

static CGameEffect * effect_int1(int32_t type, int32_t val) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = type;
    eff->eff_integers[0] = val;
    
    return eff;
}

static CGameEffect * effect_state(int32_t type) {
    return effect_int1(EFFECT_TRUETYPE_SETSTATE, type);
}

CGameEffect * effect_ability(int32_t ability, int32_t amount) {
    CGameEffect *eff = nwn_CreateEffect(1);
    if ( ability < ABILITY_STRENGTH || ability > ABILITY_CHARISMA)
        ability = ABILITY_STRENGTH;

    int type = EFFECT_TRUETYPE_ABILITY_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_ABILITY_DECREASE;
        amount = -amount;
    }

    eff->eff_type = type;
    eff->eff_integers[0] = ability;
    eff->eff_integers[1] = amount;
    
    return eff;
}

CGameEffect * effect_ac(int32_t amount, int32_t modifier_type, int32_t damage_type) {

    CGameEffect *eff = nwn_CreateEffect(1);
    if ( modifier_type < 0 || modifier_type > 6)
        modifier_type = 0;

    int type = EFFECT_TRUETYPE_AC_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_AC_DECREASE;
        amount = -amount;
    }

    eff->eff_type = type;
    eff->eff_integers[0] = modifier_type;
    eff->eff_integers[1] = amount;
    eff->eff_integers[2] = RACIAL_TYPE_INVALID;
    eff->eff_integers[5] = damage_type;
    
    return eff;
}

CGameEffect * effect_appear(bool animation) {
    return effect_int1(EFFECT_TRUETYPE_APPEAR, animation);
}

CGameEffect * effect_aoe(int32_t aoe, const char * enter, const char * heartbeat, const char * exit) {

}

CGameEffect * effect_attack(int32_t amount, int32_t modifier_type) {
    CGameEffect *eff = nwn_CreateEffect(1);
    if ( modifier_type < ATTACK_TYPE_MISC ||
         modifier_type > ATTACK_TYPE_EXTRA2) {
        modifier_type = ATTACK_TYPE_MISC;
    }

    int type = EFFECT_TRUETYPE_ATTACK_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_ATTACK_DECREASE;
        amount = -amount;
    }

    eff->eff_type = type;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = modifier_type;
    eff->eff_integers[2] = RACIAL_TYPE_INVALID;
    
    return eff;
}

CGameEffect * effect_beam(int32_t beam, int32_t creator, int32_t bodypart, int32_t miss_effect) {
    return NULL;
}

CGameEffect * effect_blindness() {
    return effect_int1(EFFECT_TRUETYPE_BLINDNESS, 16);
}

CGameEffect * effect_feat (int32_t feat) {
    return effect_int1(EFFECT_TRUETYPE_BONUS_FEAT, feat);
}

CGameEffect * effect_charmed() {
    return NULL;
}

CGameEffect * effect_concealment(int32_t amount, int32_t miss_type) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_CONCEALMENT;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = miss_type;
    
    return eff;
}

CGameEffect * effect_confused() {
    return effect_state(2);
}

CGameEffect * effect_curse(int32_t str, int32_t dex, int32_t con, int32_t intg, int32_t wis, int32_t cha) {

    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_CURSE;
    eff->eff_integers[0] = str;
    eff->eff_integers[1] = dex;
    eff->eff_integers[2] = con;
    eff->eff_integers[3] = intg;
    eff->eff_integers[4] = wis;
    eff->eff_integers[5] = cha;
    
    return eff;
}

CGameEffect * effect_cutscene_dominated() {
    return effect_state(21);
}

CGameEffect * effect_cutscene_ghost() {
    return effect_basic(EFFECT_TRUETYPE_CUTSCENEGHOST);
}

CGameEffect * effect_cutscene_immobilize() {
    return effect_basic(EFFECT_TRUETYPE_CUTSCENEIMMOBILE);
}

CGameEffect * effect_cutscene_paralyze() {
    return effect_state(20);
}

CGameEffect * effect_damage(int32_t amount, int32_t damage_type, int32_t power) {
    CGameEffect *eff = nwn_CreateEffect(1);
    CGameEffect__SetNumIntegers(eff, 20);
    for ( int i = 0; i < 20; ++i) {
		eff->eff_integers[i] = -1;
    }

    int dmg_index = __builtin_ffs(damage_type) - 1;

    eff->eff_type = EFFECT_TRUETYPE_DAMAGE;
    eff->eff_integers[dmg_index] = amount;
    eff->eff_integers[14] = 1000;
    eff->eff_integers[15] = damage_type;
    eff->eff_integers[16] = power; // TODO: confirm this.
    
    return eff;
}

CGameEffect * effect_damage_decrease(int32_t amount, int32_t damage_type, int32_t attack_type) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_DAMAGE_DECREASE;    
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = damage_type;
    eff->eff_integers[2] = RACIAL_TYPE_INVALID;
    
    return eff;
}

CGameEffect * effect_damage_increase(int32_t amount, int32_t damage_type, int32_t attack_type) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_DAMAGE_INCREASE;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = damage_type;
    eff->eff_integers[2] = RACIAL_TYPE_INVALID;
    
    return eff;
}

/*
  CGameEffect * effect_DamageRangeDecrease(start, stop, damage_type, attack_type) { }
  CGameEffect * effect_DamageRangeIncrease(start, stop, damage_type, attack_type) { }
*/

CGameEffect * effect_damage_immunity(int32_t damage_type, int32_t percent) {
    CGameEffect *eff = nwn_CreateEffect(1);

    int32_t type = EFFECT_TRUETYPE_DAMAGE_IMMUNITY_INCREASE;
    if ( percent < 0 ) {
        type = EFFECT_TRUETYPE_DAMAGE_IMMUNITY_DECREASE;
        percent = -percent;
    }
    
    eff->eff_type = type;
    eff->eff_integers[0] = damage_type;
    eff->eff_integers[1] = percent;
    
    return eff;
}

CGameEffect * effect_damage_reduction(int32_t amount, int32_t power, int32_t limit) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_DAMAGE_REDUCTION;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = power;
    eff->eff_integers[2] = limit;
    
    return eff;
}

CGameEffect * effect_damage_resistance(int32_t damage_type, int32_t amount, int32_t limit) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_DAMAGE_RESISTANCE;
    eff->eff_integers[0] = damage_type;
    eff->eff_integers[1] = amount;
    eff->eff_integers[2] = limit;
    
    return eff;
}

CGameEffect * effect_damage_shield(int32_t amount, int32_t random, int32_t damage_type) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_DAMAGE_SHIELD;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = random;
    eff->eff_integers[2] = damage_type;
    
    return eff;
}

CGameEffect * effect_darkness() {
    return effect_basic(EFFECT_TRUETYPE_DARKNESS);
}

CGameEffect * effect_dazed() {
    return effect_state(5);
}

CGameEffect * effect_deaf() {
    return effect_basic(EFFECT_TRUETYPE_DEAF);
}

CGameEffect * effect_death(bool spectacular, bool feedback) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_DEATH;
    eff->eff_integers[0] = spectacular;
    eff->eff_integers[1] = feedback;
    
    return eff;
}

CGameEffect * effect_disappear(bool animation) {
    return effect_int1(EFFECT_TRUETYPE_DISAPPEAR, animation);
}

CGameEffect * effect_disappear_appear(CScriptLocation location, bool animation) {
    CGameEffect *eff = effect_int1(EFFECT_TRUETYPE_DISAPPEARAPPEAR, animation);

    //SetFloats
    
    return eff;
}

CGameEffect * effect_disarm() {
    return effect_basic(EFFECT_TRUETYPE_DISARM);
}

CGameEffect * effect_disease(int32_t disease) {
    return effect_int1(EFFECT_TRUETYPE_BONUS_FEAT, disease);
}

CGameEffect * effect_dispel_all(int32_t caster_level = USE_CREATURE_LEVEL) {
    return effect_int1(EFFECT_TRUETYPE_DISPEL_ALL_MAGIC, caster_level);
}

CGameEffect * effect_dispel_best(int32_t caster_level = USE_CREATURE_LEVEL) {
    return effect_int1(EFFECT_TRUETYPE_DISPEL_BEST_MAGIC, caster_level);
}

CGameEffect * effect_dominated() {
    return effect_state(7);
}

CGameEffect * effect_entangle() {
    return effect_basic(EFFECT_TRUETYPE_ENTANGLE);
}

CGameEffect * effect_ethereal() {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_SANCTUARY;
    eff->eff_integers[0] = 8;
    eff->eff_integers[1] = RACIAL_TYPE_INVALID;
    eff->eff_integers[4] = 0;
    eff->eff_integers[5] = 0;
    
    return eff;
}

CGameEffect * effect_frightened() {
    return effect_state(3);
}

CGameEffect * effect_haste() {
    return effect_basic(EFFECT_TRUETYPE_HASTE);
}

CGameEffect * effect_heal(int32_t amount) {
    return effect_int1(EFFECT_TRUETYPE_HEAL, amount);
}

CGameEffect * effect_hp_change_when_dying(float hitpoint_change) {
    CGameEffect *eff = nwn_CreateEffect(1);

    CGameEffect__SetFloat(eff, 0, hitpoint_change);
    
    return eff;  
}

/*
  CGameEffect * effect_hp_decrease(amount) { }
  CGameEffect * effect_hp_increase(amount) { }
*/

CGameEffect * effect_icon(int32_t icon) {
    return effect_int1(EFFECT_TRUETYPE_ICON, icon);
}

CGameEffect * effect_immunity(int32_t immunity, int32_t percent = 100) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_IMMUNITY;
    eff->eff_integers[0] = immunity;
    eff->eff_integers[1] = RACIAL_TYPE_INVALID;
    eff->eff_integers[4] = percent;
    
    return eff;  
}

CGameEffect * effect_invisibility(int32_t type) {
    return effect_int1(EFFECT_TRUETYPE_INVISIBILITY, type);
}

CGameEffect * effect_knockdown() {
    return effect_basic(EFFECT_TRUETYPE_KNOCKDOWN);
}

CGameEffect * effect_link(CGameEffect *child, CGameEffect *parent) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_LINK;
    CGameEffect__SetLinked(eff, child, parent);
    CGameEffect__UpdateLinked(eff);

    return eff;
}

CGameEffect * effect_miss_chance(int32_t amount, int32_t miss_type) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_MISS_CHANCE;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = miss_type;
    
    return eff;
}

CGameEffect * effect_additional_attacks(int32_t amount) {
    return effect_int1(EFFECT_TRUETYPE_MODIFYNUMATTACKS, amount);
}

CGameEffect * effect_move_speed(int32_t amount) {
    int type = EFFECT_TRUETYPE_MOVEMENT_SPEED_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_MOVEMENT_SPEED_DECREASE;
        amount = -amount;
    }

    return effect_int1(type, amount);
}

CGameEffect * effect_negative_level(int32_t amount, bool hp_bonus) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_NEGATIVE_LEVEL;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = hp_bonus;
    
    return eff;
}

CGameEffect * effect_paralyze() {
    return effect_state(8);
}

CGameEffect * effect_petrify() {
    return effect_state(15);
}

CGameEffect * effect_poison(int32_t type) {
    return effect_int1(EFFECT_TRUETYPE_INVISIBILITY, type);
}

CGameEffect * effect_polymorph(int32_t polymorph, bool locked) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_POLYMORPH;
    eff->eff_integers[0] = polymorph;
    eff->eff_integers[1] = 0;
    eff->eff_integers[2] = locked;
    
    return eff;
}

CGameEffect * effect_regen(int32_t amount, float interval) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_REGENERATE;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = static_cast<int>(1000.0 * interval);

    return eff;
}

CGameEffect * effect_resurrection() {
    return effect_basic(EFFECT_TRUETYPE_RESURRECTION);
}

CGameEffect * effect_sanctuary(int32_t dc) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_SANCTUARY;
    eff->eff_integers[0] = 8;
    eff->eff_integers[1] = RACIAL_TYPE_INVALID;
    eff->eff_integers[4] = dc;
    eff->eff_integers[5] = 1;
    
    return eff;
}

CGameEffect * effect_save(int32_t save, int32_t amount, int32_t save_type) {

    int32_t type = EFFECT_TRUETYPE_SAVING_THROW_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_SAVING_THROW_DECREASE;
        amount = -amount;
    }

    CGameEffect *eff = nwn_CreateEffect(1);
   
    eff->eff_type = type;
    eff->eff_integers[0] = amount;
    eff->eff_integers[1] = save;
    eff->eff_integers[2] = save_type;
    eff->eff_integers[3] = RACIAL_TYPE_INVALID;
   
    return eff;
}

CGameEffect * effect_see_invisible() {
    return effect_basic(EFFECT_TRUETYPE_SEEINVISIBLE);
}

CGameEffect * effect_silence() {
    return effect_basic(EFFECT_TRUETYPE_SILENCE);
}

CGameEffect * effect_skill(int32_t skill, int32_t amount) {
    CGameEffect *eff = nwn_CreateEffect(1);

    int32_t type = EFFECT_TRUETYPE_SKILL_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_SKILL_DECREASE;
        amount = -amount;
    }

    eff->eff_type = type;
    eff->eff_integers[0] = skill;
    eff->eff_integers[1] = amount;
    eff->eff_integers[2] = RACIAL_TYPE_INVALID;
   
    return eff;
}

CGameEffect * effect_sleep() {
    return effect_state(9);
}

CGameEffect * effect_slow() {
    return effect_basic(EFFECT_TRUETYPE_SLOW);
}

CGameEffect * effect_spell_failure(int32_t percent, int32_t spell_school) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_SPELL_FAILURE;
    eff->eff_integers[0] = percent;
    eff->eff_integers[1] = spell_school;
    
    return eff;   
}

CGameEffect * effect_spell_immunity(int32_t spell) {
    return effect_int1(EFFECT_TRUETYPE_SPELL_IMMUNITY, spell);
}

CGameEffect * effect_spell_absorbtion(int32_t max_level, int32_t max_spells, int32_t school) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_SPELL_LEVEL_ABSORPTION;
    eff->eff_integers[0] = max_level;
    eff->eff_integers[1] = max_spells;
    eff->eff_integers[2] = school;
    
    return eff;
}

CGameEffect * effect_spell_resistance(int32_t amount) {
    int32_t type = EFFECT_TRUETYPE_SPELL_RESISTANCE_INCREASE;

    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_MOVEMENT_SPEED_DECREASE;
        amount = -amount;
    }

    return effect_int1(type, amount);
}

CGameEffect * effect_stunned() {
    return effect_state(6);
}

CGameEffect * effect_summon(const char * resref, int32_t vfx, float delay, bool appear) {
    CGameEffect *eff = nwn_CreateEffect(1);

    CExoString s;
    s.text = strdup(resref);
    
    eff->eff_type = EFFECT_TRUETYPE_SUMMON_CREATURE;
    //CGameEffect__SetString(eff, 0, resref);

    eff->eff_integers[0] = vfx;
    eff->eff_integers[1] = appear;
    
    CGameEffect__SetFloat(eff, 0, delay);

    free(s.text);
    
    return eff;
}

CGameEffect * effect_swarm(bool looping, const char * res1, const char * res2, const char * res3, const char * res4) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_SWARM;
/*
  eff->SetString(0, res1);
  eff->SetString(1, res2);
  eff->SetString(2, res3);
  eff->SetString(3, res4);
*/
    eff->eff_integers[0] =  looping;
    
    return eff;
}

CGameEffect * effect_hp_temporary(int32_t amount) {
    return effect_int1(EFFECT_TRUETYPE_TEMPORARY_HITPOINTS, amount);
}

CGameEffect * effect_time_stop() {
    return effect_basic(EFFECT_TRUETYPE_TIMESTOP);
}

CGameEffect * effect_true_seeing() {
    return effect_basic(EFFECT_TRUETYPE_TRUESEEING);
}

CGameEffect * effect_turned() {
    return effect_state(4);
}

CGameEffect * effect_turn_resistance(int32_t amount) {
    int32_t type = EFFECT_TRUETYPE_TURN_RESISTANCE_INCREASE;
    if ( amount < 0 ) {
        type = EFFECT_TRUETYPE_TURN_RESISTANCE_INCREASE;
        amount = -amount;
    }

    return effect_int1(type, amount);
}

CGameEffect * effect_ultravision() {
    return effect_basic(EFFECT_TRUETYPE_ULTRAVISION);
}

CGameEffect * effect_visual(int32_t id, bool miss) {
    CGameEffect *eff = nwn_CreateEffect(1);

    eff->eff_type = EFFECT_TRUETYPE_VISUALEFFECT;
    eff->eff_integers[0] = id;
    eff->eff_integers[2] = miss;
    
    return eff;
}

CGameEffect * effect_wounding (int32_t amount) {
    return effect_int1(EFFECT_TRUETYPE_WOUNDING, amount);
}
