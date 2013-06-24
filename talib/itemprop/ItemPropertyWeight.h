#ifndef TALIB_ITEMPROP_WEIGHT_H
#define TALIB_ITEMPROP_WEIGHT_H

struct ItemPropertyWeight {
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
        C2DA *dmg = nwn_GetCached2da("iprp_weightcost");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "Weight Reduction: ";
        float f = nwn_Get2daFloat(dmg, "Value", ip->ip_cost_value);
        ss << int(f * 10 + 0.5) << '%';

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyWeightIncrease {
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

    static std::string toString(CNWItemProperty* ip, int32_t version) {
        C2DA *dmg = (*NWN_Rules)->ru_2das->tda_iprp_weightinc;
        std::stringstream ss;

        ss << "Weight Increase: ";
        ss << nwn_Get2daInt(dmg, "Value", ip->ip_param_value);
        ss << "lbs.";

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyContainerWeight {
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
        return "ItemPropertyContainerWeight";
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_WEIGHT_H
