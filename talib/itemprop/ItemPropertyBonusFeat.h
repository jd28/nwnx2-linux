#ifndef TALIB_ITEMPROP_BONUS_FEAT_H
#define TALIB_ITEMPROP_BONUS_FEAT_H

struct ItemPropertyBonusFeat {
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
        ss << "Bonus Feat: ";
        ss << "TODO"; //nwn_GetFeatName(ip->ip_cost_value);
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_BONUS_FEAT_H
