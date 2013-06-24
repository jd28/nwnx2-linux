#include "NWNXLib.h"

bool nwn_GetIsClassBonusFeat(int32_t idx, uint16_t feat){
    if (idx < 0 || idx >= (*NWN_Rules)->ru_classes_len)
        return 0;
    
    CNWClass *cls = &((*NWN_Rules)->ru_classes[idx]);
    return !!CNWClass__IsBonusFeat(cls, feat);
}

bool nwn_GetIsClassGeneralFeat(int32_t idx, uint16_t feat){
    if (idx < 0 || idx >= (*NWN_Rules)->ru_classes_len)
        return false;
    
    CNWClass *cls = &((*NWN_Rules)->ru_classes[idx]);
    return !!CNWClass__IsNormalFeat(cls, feat);
}

uint8_t nwn_GetIsClassGrantedFeat(int32_t idx, unsigned short feat){
    uint8_t level = 0;
    if (idx < 0 || idx >= (*NWN_Rules)->ru_classes_len)
        return 0;
    
    CNWClass *cls = &((*NWN_Rules)->ru_classes[idx]);
    int ret = CNWClass__IsGrantedFeat(cls, feat, &level);
    if (ret) return level;

    return 0;
}

bool nwn_GetIsClassSkill (int32_t idx, uint16_t skill) {
    int ret;

    if (idx < 0 || idx >= (*NWN_Rules)->ru_classes_len) {
        return 0;
    }

    CNWClass *cls = &((*NWN_Rules)->ru_classes[idx]);
    if (!CNWClass__IsSkillUseable(cls, skill))
        ret = false;
    else
        ret = !!CNWClass__IsSkillClassSkill(cls, skill);

    return ret;
}

CNWSkill *nwn_GetSkill(uint32_t skill) {
    if ( skill < 0 || skill >= (*NWN_Rules)->ru_skills_len ) {
        return NULL;
    }
    return &(*NWN_Rules)->ru_skills[skill];
}

const char *nwn_GetAbilityName(uint32_t abil) {
    switch (abil) {
    default: return "Unknown";
    case ABILITY_STRENGTH: return "Strength";
    case ABILITY_DEXTERITY: return "Dexterity";
    case ABILITY_CONSTITUTION: return "Constitution";
    case ABILITY_WISDOM: return "Wisdom";
    case ABILITY_INTELLIGENCE: return "Itelligence";
    case ABILITY_CHARISMA: return "Charisma";
    }
}

const char *nwn_GetArmorClassName(uint32_t val) {
    switch (val) {
    default: return "Unknown";
    case AC_DODGE_BONUS: return "Dodge";
    case AC_NATURAL_BONUS: return "Natural";
    case AC_ARMOUR_ENCHANTMENT_BONUS: return "Armor";
    case AC_SHIELD_ENCHANTMENT_BONUS: return "Shield";
    case AC_DEFLECTION_BONUS: return "Deflection";
    }
}

const char *nwn_GetSkillName(uint32_t skill) {
    switch(skill) {
    default:                     return "Unknown";
    case SKILL_ANIMAL_EMPATHY:   return "Animal Empathy";
    case SKILL_CONCENTRATION:    return "Concentration";
    case SKILL_DISABLE_TRAP:     return "Disable Trap";
    case SKILL_DISCIPLINE:       return "Discipline";
    case SKILL_HEAL:             return "Heal";
    case SKILL_HIDE:             return "Hide";
    case SKILL_LISTEN:           return "Listen";
    case SKILL_LORE:             return "Lore";
    case SKILL_MOVE_SILENTLY:    return "Move Silently";
    case SKILL_OPEN_LOCK:        return "Open Lock";
    case SKILL_PARRY:            return "Parry";
    case SKILL_PERFORM:          return "Perform";
    case SKILL_PERSUADE:         return "Persuade";
    case SKILL_PICK_POCKET:      return "Pick Pocket";
    case SKILL_SEARCH:           return "Search";
    case SKILL_SET_TRAP:         return "Set Trap";
    case SKILL_SPELLCRAFT:       return "Spellcraft";
    case SKILL_SPOT:             return "Spot";
    case SKILL_TAUNT:            return "Taunt";
    case SKILL_USE_MAGIC_DEVICE: return "Use Magical Device";
    case SKILL_APPRAISE:         return "Apraise";
    case SKILL_TUMBLE:           return "Tumble";
    case SKILL_CRAFT_TRAP:       return "Craft Trap";
    case SKILL_BLUFF:            return "Bluff";
    case SKILL_INTIMIDATE:       return "Intimidate";
    case SKILL_CRAFT_ARMOR:      return "Craft Armor";
    case SKILL_CRAFT_WEAPON:     return "Craft Weapon";
    case SKILL_RIDE:             return "Ride";
    }
}

const char *nwn_GetMiscImmunityName(uint32_t val) {
    switch(val) {
    default: return "Unknown";
    case IMMUNITY_TYPE_MIND_SPELLS:               return "Mind-affecting Spells";
    case IMMUNITY_TYPE_POISON:                    return "Poison";
    case IMMUNITY_TYPE_DISEASE:                   return "Disease";
    case IMMUNITY_TYPE_FEAR:                      return "Fear";
    case IMMUNITY_TYPE_TRAP:                      return "Traps";
    case IMMUNITY_TYPE_PARALYSIS:                 return "Paralysis";
    case IMMUNITY_TYPE_BLINDNESS:                 return "Blindness";
    case IMMUNITY_TYPE_DEAFNESS:                  return "Deafness";
    case IMMUNITY_TYPE_SLOW:                      return "Slow";
    case IMMUNITY_TYPE_ENTANGLE:                  return "Entangle";
    case IMMUNITY_TYPE_SILENCE:                   return "Silence";
    case IMMUNITY_TYPE_STUN:                      return "Stun";
    case IMMUNITY_TYPE_SLEEP:                     return "Sleep";
    case IMMUNITY_TYPE_CHARM:                     return "Charm";
    case IMMUNITY_TYPE_DOMINATE:                  return "Domination";
    case IMMUNITY_TYPE_CONFUSED:                  return "Confusion";
    case IMMUNITY_TYPE_CURSED:                    return "Curse";
    case IMMUNITY_TYPE_DAZED:                     return "Dazed";
    case IMMUNITY_TYPE_ABILITY_DECREASE:          return "Ability Decrease";
    case IMMUNITY_TYPE_ATTACK_DECREASE:           return "Attack Decrease";
    case IMMUNITY_TYPE_DAMAGE_DECREASE:           return "Damage Decrease";
    case IMMUNITY_TYPE_DAMAGE_IMMUNITY_DECREASE:  return "Damage Immunity Decrease";
    case IMMUNITY_TYPE_AC_DECREASE:               return "Armor Class Decrease";
    case IMMUNITY_TYPE_MOVEMENT_SPEED_DECREASE:   return "Movement Speed Decrease";
    case IMMUNITY_TYPE_SAVING_THROW_DECREASE:     return "Saving Throw Decrease";
    case IMMUNITY_TYPE_SPELL_RESISTANCE_DECREASE: return "Spell Resistance Decrease";
    case IMMUNITY_TYPE_SKILL_DECREASE:            return "Skill Decrease";
    case IMMUNITY_TYPE_KNOCKDOWN:                 return "Knockdown";
    case IMMUNITY_TYPE_NEGATIVE_LEVEL:            return "Negative Level";
    case IMMUNITY_TYPE_SNEAK_ATTACK:              return "Sneak Attack";
    case IMMUNITY_TYPE_CRITICAL_HIT:              return "Critical Hit";
    case IMMUNITY_TYPE_DEATH:                     return "Death";
    }
}
