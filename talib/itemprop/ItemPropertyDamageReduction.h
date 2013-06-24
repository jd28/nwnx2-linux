#ifndef TALIB_ITEMPROP_DAMAGE_REDUCTION_H
#define TALIB_ITEMPROP_DAMAGE_REDUCTION_H

struct ItemPropertyDamageReduction {
    static int32_t apply(CNWItemProperty* ip, CNWSItem *item, CNWSCreature *cre,
                         int32_t version) {
        return 0;
    }

    static int32_t getCost(CNWItemProperty* ip, int32_t version) {
        return 0;
    }

    static int32_t remove(CNWItemProperty* ip, CNWSItem *item, CNWSCreature *cre, int32_t version) {
        return 0;
    }

    static std::string toString(CNWItemProperty* ip, int32_t version) {
        C2DA *dmg = nwn_GetCached2da("iprp_soakcost");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "Damage Reduction: ";
        ss << nwn_Get2daInt(dmg, "Amount", ip->ip_cost_value);
        ss << "/+" << ip->ip_subtype + 1;

        return ss.str();
    }

    static void update(CNWItemProperty* ip, int32_t version) {}
};

#endif // TALIB_ITEMPROP_DAMAGE_REDUCTION_H
