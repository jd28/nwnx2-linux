#ifndef TALIB_ITEMPROP_ABILITY_H
#define TALIB_ITEMPROP_ABILITY_H

extern "C" {
#include "../rules.h"
}

struct ItemPropertyAbility {
    static int32_t apply(CNWItemProperty* ip, 
                         CNWSItem *item, 
                         CNWSCreature *cre,
                         int32_t version) {
        return 0;
    }

    static int32_t getCost(CNWItemProperty* ip,
                           int32_t version) {
        return 0;
    }

    static int32_t remove(CNWItemProperty* ip,
                          CNWSItem *item,
                          CNWSCreature *cre,
                          int32_t version) {
        return 0;
    }

    static std::string toString(CNWItemProperty* ip,
                                int32_t version) {
        std::stringstream ss;
        ss << "Ability Bonus: ";
        ss << nwn_GetAbilityName(ip->ip_subtype);
        ss << " +" << (uint32_t)ip->ip_cost_value;
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {
	
    }
};

struct ItemPropertyAbilityPenalty {
    static int32_t apply(CNWItemProperty* ip, 
                         CNWSItem *item, 
                         CNWSCreature *cre,
                         int32_t version) {
        return 0;
    }

    static int32_t getCost(CNWItemProperty* ip,
                           int32_t version) {
        return 0;
    }

    static int32_t remove(CNWItemProperty* ip,
                          CNWSItem *item,
                          CNWSCreature *cre,
                          int32_t version) {
        return 0;
    }

    static std::string toString(CNWItemProperty* ip,
                                int32_t version) {
        std::stringstream ss;
        ss << "Ability Penalty: ";
        ss << nwn_GetAbilityName(ip->ip_subtype);
        ss << " -" << (uint32_t)ip->ip_cost_value;
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {
	
    }
};

#endif // TALIB_ITEMPROP_ABILITY_H
