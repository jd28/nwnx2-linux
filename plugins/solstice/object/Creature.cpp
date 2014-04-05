#include "NWNXSolstice.h"
#include "Creature.h"

#include <iostream>
#include <sstream>
#include <string>

extern CNWNXSolstice solstice;
extern lua_State *L;

void Creature::update() {
    if(!nl_pushfunction(L, "NWNXSolstice_UpdateCombatInfo"))
        return;

    lua_pushinteger(L, original->obj.obj_id);
    lua_pushinteger(L, OBJECT_INVALID);

    if (lua_pcall(L, 2, 0, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_UpdateCombatInfo : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        return;
    }
}


/*
static void dump_combat_mod(std::string name, std::ostringstream& out, const CombatMod& mod) {
    out << name << '\n'
        << " AB: " << mod.ab
        << " AC: " << mod.ac
        << " HP: " << mod.hp
        << " Damage: " << mod.dmg << '\n';
}

void Creature::log() {
    combat.Log(0, (char*)toString().c_str());
}

std::string Creature::getCombatModString() {
    std::ostringstream out;
    out << "Combat Mods:\n";

    dump_combat_mod("Favored Enemy:", out, mod_favored_enemy);
    dump_combat_mod("Training Vs.:", out, mod_training_vs);

    for ( int i = 0; i < COMBAT_SITUATION_NUM; ++i ) {
        dump_combat_mod("Situations:", out, mod_situ[i]);
    }
    return out.str();
}

std::string Creature::toString() {
    return getCombatModString();
}

CombatMod *Creature::getSituationalModifier(uint32_t index) {
    if ( index < 0 || index >= COMBAT_SITUATION_NUM ) {
        return nullptr;
    }

    return &mod_situ[index];
}

int8_t Creature::getAbilityEffectModifier(uint8_t ability) {
    if ( ability < 0 || ability > 5 ) { return 0; }
    return CLAMP<int16_t>(ability_eff[ability], -12, 12);
}

bool Creature::hasTrainingVersus(uint16_t race) {
    return (training_vs_mask & (1 << race));
}

bool Creature::isFavoredEnemy(uint16_t race) {
    return (fe_mask & (1 << race));
}

void Creature::modifyAbilityEffect(uint8_t ability, int32_t amount) {
    if ( ability < 0 || ability > 5 ) { return; }
    ability_eff[ability] += amount;
}

int8_t Creature::getSkillRank(uint8_t skill, CNWSObject *vs, bool base) {
    if ( skill < 0 || skill > SKILL_LAST ) { return 0; }
    if ( original_->cre_stats->cs_is_dm ) { return 127; }

    CNWSkill sk = (*NWN_Rules)->ru_skills[skill];
    int32_t result = original_->cre_stats->cs_skills[skill];

    // If it's not an untrained, creature must have some base skill.
    if ( !sk.sk_untrained && result == 0 ) { return 0; }

    if ( base ) { return result; }

    result += getSkillEffectModifier(skill);
    result += nwn_GetAbilityModifier(original_->cre_stats, sk.sk_ability, false);

    if ( sk.sk_armor_check ) {
        result += original_->cre_stats->cs_acp_armor;
        result += original_->cre_stats->cs_acp_shield;
    }

    result += CNWSCreatureStats__GetTotalNegativeLevels(original_->cre_stats);
    result += GetSkillFeatBonus(original_, skill);

    // Blind creatures get a -4 to skill checks.
    if ( CNWSCreature__GetBlind(original_) ) {
        result -= 4;
    }

    return CLAMP<int8_t>(result, -127, 127);
}

int8_t Creature::getSkillEffectModifier(uint8_t skill) {
    if ( skill < 0 || skill > SKILL_LAST ) { return 0; }
    return CLAMP<int16_t>(skill_eff[skill], -10, 50);
}

void Creature::modifySkillEffect(uint8_t skill, int32_t amount) {
    if ( skill < 0 || skill > SKILL_LAST ) { return; }
    skill_eff[skill] += amount;
}

void Creature::update() {
    if ( original_ == NULL ) { return; }

    offense.update();
    defense.update();

    fe_mask = GetFavoredEnemyMask(original_);
    training_vs_mask = GetTrainingVsMask(original_);

    for ( int i = 0; i < COMBAT_SITUATION_NUM; ++i ) {
        mod_situ[i] = GetCombatModSituation(original_, i);
    }
}

void Creature::updateMode() {
    mode_ = GetCombatModeMod(original_);
}
*/
