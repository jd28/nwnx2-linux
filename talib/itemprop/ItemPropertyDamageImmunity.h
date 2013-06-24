#ifndef TALIB_ITEMPROP_DAMAGE_IMMUNITY_H
#define TALIB_ITEMPROP_DAMAGE_IMMUNITY_H

struct ItemPropertyDamageImmunity {
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
        C2DA *dmg = nwn_GetCached2da("iprp_immuncost");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "Damage Immunity: ";
        ss << DamageIndexToString(GetDamageIndexFromIPConst(ip->ip_subtype));
        ss << ' ' << nwn_Get2daInt(dmg, "Value", ip->ip_cost_value);
        ss << '%';

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyDamageVulnerability {
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
        C2DA *dmg = nwn_GetCached2da("iprp_damvulcost");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "Damage Vulnerability: ";
        ss << DamageIndexToString(GetDamageIndexFromIPConst(ip->ip_subtype));
        ss << ' ' << nwn_Get2daInt(dmg, "Value", ip->ip_cost_value);
        ss << '%';

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_DAMAGE_IMMUNITY_H
