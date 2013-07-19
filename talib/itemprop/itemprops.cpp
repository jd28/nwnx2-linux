#include "NWNXLib.h"
#include "../nwn/all.h"

#include "itemprops.h"
#include <sstream>
#include "ItemPropertyInvalid.h"
#include "ItemPropertyAbility.h"
#include "ItemPropertyAC.h"
#include "ItemPropertyAdditional.h"
#include "ItemPropertyArcaneSpellFailure.h"
#include "ItemPropertyAttackModifiers.h"
#include "ItemPropertyBonusFeat.h"
#include "ItemPropertyBonusSpellSlot.h"
#include "ItemPropertyCastSpell.h"
#include "ItemPropertyDamage.h"
#include "ItemPropertyDamageImmunity.h"
#include "ItemPropertyDamageReduction.h"
#include "ItemPropertyDamageResistance.h"
#include "ItemPropertyExtraDamage.h"
#include "ItemPropertyLight.h"
#include "ItemPropertyMaterial.h"
#include "ItemPropertyMisc.h"
#include "ItemPropertyMiscImmunity.h"
#include "ItemPropertyOnHit.h"
#include "ItemPropertyOnHitCastSpell.h"
#include "ItemPropertyOnMonsterHit.h"
#include "ItemPropertyPoison.h"
#include "ItemPropertyQuality.h"
#include "ItemPropertyRegeneration.h"
#include "ItemPropertySavingThrow.h"
#include "ItemPropertySkill.h"
#include "ItemPropertySpellImmunity.h"
#include "ItemPropertySpellResistance.h"
#include "ItemPropertyTrap.h"
#include "ItemPropertyTurnResistance.h"
#include "ItemPropertyUnlimitedAmmo.h"
#include "ItemPropertyUseLimit.h"
#include "ItemPropertyVisualEffect.h"
#include "ItemPropertyWeaponModifiers.h"
#include "ItemPropertyWeight.h"

#define ITEM_PROPERTY_DISPATCH(type, app, cost, rem, str, upd)      \
    { (app ? type::apply : NULL),                                   \
            (cost ? type::getCost  : NULL),                         \
            (rem  ? type::remove   : NULL),                         \
            (str  ? type::toString : NULL),                         \
            (upd  ? type::update   : NULL) }

const ItemPropertyDispatch 
ItemProperties::invalid_ = ITEM_PROPERTY_DISPATCH(ItemPropertyInvalid, true, true, true, true, true);

std::vector<ItemPropertyDispatch> ItemProperties::itemprops_ = {
    ITEM_PROPERTY_DISPATCH(ItemPropertyAbility, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyAC, false, false, false, true, false),
    invalid_, // ITEM_PROPERTY_AC_BONUS_VS_ALIGNMENT_GROUP
    invalid_, // ITEM_PROPERTY_AC_BONUS_VS_DAMAGE_TYPE
    invalid_, // ITEM_PROPERTY_AC_BONUS_VS_RACIAL_GROUP
    invalid_, // ITEM_PROPERTY_AC_BONUS_VS_SPECIFIC_ALIGNMENT
    ITEM_PROPERTY_DISPATCH(ItemPropertyEnhancement, false, false, false, true, false),
    invalid_, // ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_ALIGNMENT_GROUP
    invalid_, // ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_RACIAL_GROUP
    invalid_, // ITEM_PROPERTY_ENHANCEMENT_BONUS_VS_SPECIFIC_ALIGNEMENT
    ITEM_PROPERTY_DISPATCH(ItemPropertyEnhancementPenalty, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyWeight, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyBonusFeat, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyBonusSpellSlot, false, false, false, true, false),
    invalid_, // Boomerang
    ITEM_PROPERTY_DISPATCH(ItemPropertyCastSpell, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamage, false, false, false, true, false),
    invalid_, // ITEM_PROPERTY_DAMAGE_BONUS_VS_ALIGNMENT_GROUP
    invalid_, // ITEM_PROPERTY_DAMAGE_BONUS_VS_RACIAL_GROUP
    invalid_, // ITEM_PROPERTY_DAMAGE_BONUS_VS_SPECIFIC_ALIGNMENT
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamageImmunity, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamageDecrease, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamageReduction, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamageResistance, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamageVulnerability, false, false, false, true, false),
    invalid_, // Dancing Scimitar
    ITEM_PROPERTY_DISPATCH(ItemPropertyDarkvision, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyAbilityPenalty, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyACPenalty, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySkillPenalty, false, false, false, true, false),
    invalid_, // DoubleStack
    invalid_, // EnhancedContainer_BonusSlot
    ITEM_PROPERTY_DISPATCH(ItemPropertyContainerWeight, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyExtraDamageMelee, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyExtraDamageRanged, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyHaste, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyHolyAvenger, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyMiscImmunity, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyImprovedEvasion, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySpellResistance, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySavingThrow, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySavingThrowVs, false, false, false, true, false),
    invalid_, // deleted
    ITEM_PROPERTY_DISPATCH(ItemPropertyKeen, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyLight, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyMighty, false, false, false, true, false),
    invalid_, // ITEM_PROPERTY_DISPATCH(ItemPropertyMindBlank, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyDamageNone, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyOnHit, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySavingThrowPenalty, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySavingThrowVsPenalty, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyRegeneration, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySkill, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySpellImmunity, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySpellSchoolImmunity, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyThievesTools, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyAttackBonus, false, false, false, true, false),
    invalid_, // ITEM_PROPERTY_ATTACK_BONUS_VS_ALIGNMENT_GROUP
    invalid_, // ITEM_PROPERTY_ATTACK_BONUS_VS_RACIAL_GROUP
    invalid_, // ITEM_PROPERTY_ATTACK_BONUS_VS_SPECIFIC_ALIGNMENT 
    ITEM_PROPERTY_DISPATCH(ItemPropertyAttackPenalty, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyUnlimitedAmmo, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyUseLimit, false, false, false, true, false), // Align
    ITEM_PROPERTY_DISPATCH(ItemPropertyUseLimit, false, false, false, true, false), // Class
    ITEM_PROPERTY_DISPATCH(ItemPropertyUseLimit, false, false, false, true, false), // Race
    ITEM_PROPERTY_DISPATCH(ItemPropertyUseLimit, false, false, false, true, false), // Specific Align
    invalid_, // Use limit terrain.
    invalid_, // ITEM_PROPERTY_DISPATCH(ItemPropertyVampiricRegen, false, false, false, true, false),
    invalid_, // Old vorpal.
    invalid_, // Old wounding.
    ITEM_PROPERTY_DISPATCH(ItemPropertyTrap, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyTrueSeeing, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyOnMonsterHit, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyTurnResistance, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyMassiveCriticals, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyFreedom, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyPoison, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyMonsterDamage, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySpellLevelImmunity, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertySpecialWalk, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyHealersKit, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyWeightIncrease, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyOnHitCastSpell, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyVisualEffect, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyArcaneSpellFailure, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyMaterial, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyQuality, false, false, false, true, false),
    ITEM_PROPERTY_DISPATCH(ItemPropertyAdditional, false, false, false, true, false),
/* */
};

std::pair<bool, int32_t>
ItemProperties::apply(CNWItemProperty* ip, 
                      CNWSItem *item, 
                      CNWSCreature *cre,
                      int32_t version) {
    
    if ( ip->ip_type < 0                  || 
         ip->ip_type >= itemprops_.size() ||
         itemprops_[ip->ip_type].apply == NULL ) {
        return std::make_pair(false, 0);
    }

    return std::make_pair(true,
                          itemprops_[ip->ip_type].apply(ip, item, cre, version));
}

std::pair<bool, int32_t> ItemProperties::getCost(CNWItemProperty* ip, int32_t version) {
    if ( ip->ip_type < 0                  || 
         ip->ip_type >= itemprops_.size() ||
         itemprops_[ip->ip_type].getCost == NULL ) {
        return std::make_pair(false, ItemPropertyInvalid::getCost(ip, version));
    }

    return std::make_pair(true,
                          itemprops_[ip->ip_type].getCost(ip, version));
}

std::pair<bool, int32_t> 
ItemProperties::remove(CNWItemProperty* ip, 
                       CNWSItem *item, 
                       CNWSCreature *cre, 
                       int32_t version) {
    
    if ( ip->ip_type < 0                  ||
         ip->ip_type >= itemprops_.size() ||
         itemprops_[ip->ip_type].remove == NULL ) {
        return std::make_pair(false, 0);
    }

    return std::make_pair(true,
                          itemprops_[ip->ip_type].remove(ip, item, cre, version));
}

std::pair<bool, std::string>
ItemProperties::toString(CNWItemProperty* ip, 
                         int32_t version) {
    if ( ip->ip_type < 0                  || 
         ip->ip_type >= itemprops_.size() ||
         itemprops_[ip->ip_type].toString == NULL ) {
        return std::make_pair(false,
                              ItemPropertyInvalid::toString(ip, version));
    }

    return std::make_pair(true,
                          itemprops_[ip->ip_type].toString(ip, version));
}

bool ItemProperties::update(CNWItemProperty* ip, int32_t version) {
    if ( ip->ip_type < 0                  || 
         ip->ip_type >= itemprops_.size() ||
         itemprops_[ip->ip_type].update == NULL ) {
        return false;
    }

    itemprops_[ip->ip_type].update(ip, version);
    return true;
}
