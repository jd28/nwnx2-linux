#ifndef TALIB_ITEMPROP_AC_H
#define TALIB_ITEMPROP_AC_H

extern "C" {
#include "../rules.h"
}

struct ItemPropertyAC {
    static int32_t apply(CNWItemProperty* ip, CNWSItem *item, CNWSCreature *cre,
                         int32_t version) {
        return 0;
    }

    static int32_t getCost(CNWItemProperty* ip,
                           int32_t version) {
        return 0;
    }

    static int32_t remove(CNWItemProperty* ip, CNWSItem *item, CNWSCreature *cre,
                          int32_t version) {
        return 0;
    }

    static std::string toString(CNWItemProperty* ip,
                                int32_t version) {
        std::stringstream ss;
        ss << "Armor Bonus: ";
        ss << "+" << (uint32_t)ip->ip_cost_value;
        ss << " (" << nwn_GetArmorClassName(ip->ip_subtype) << ')';
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyACPenalty {
    static int32_t apply(CNWItemProperty* ip, CNWSItem *item, CNWSCreature *cre,
                         int32_t version) {
        return 0;
    }

    static int32_t getCost(CNWItemProperty* ip,
                           int32_t version) {
        return 0;
    }

    static int32_t remove(CNWItemProperty* ip, CNWSItem *item, CNWSCreature *cre,
                          int32_t version) {
        return 0;
    }

    static std::string toString(CNWItemProperty* ip,
                                int32_t version) {
        std::stringstream ss;
        ss << "Armor Penalty: ";
        ss << nwn_GetArmorClassName(ip->ip_subtype);
        ss << " -" << (uint32_t)ip->ip_cost_value;
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_AC_H
