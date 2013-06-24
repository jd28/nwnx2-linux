#ifndef TALIB_ITEMPROP_TURN_RESISTANCE_H
#define TALIB_ITEMPROP_TURN_RESISTANCE_H

struct ItemPropertyTurnResistance {
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
        ss << "Turn Resistance: +" << ip->ip_cost_value;
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_TURN_RESISTANCE_H
