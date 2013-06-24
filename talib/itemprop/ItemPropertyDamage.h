#ifndef TALIB_ITEMPROP_DAMAGE_H
#define TALIB_ITEMPROP_DAMAGE_H

struct ItemPropertyDamage {
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
        C2DA *dmg = nwn_GetCached2da("iprp_damagecost");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "Damage Bonus: ";
        ss << DamageIndexToString(GetDamageIndexFromIPConst(ip->ip_subtype));
        ss << ' ' << nwn_Get2daInt(dmg, "NumDice", ip->ip_cost_value);
        ss << 'd' << nwn_Get2daInt(dmg, "Die", ip->ip_cost_value);

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyDamageDecrease {
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

        ss << "Damage Penalty: -" << ip->ip_cost_value;

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyMonsterDamage {
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
        C2DA *dmg = (*NWN_Rules)->ru_2das->tda_iprp_monstcost;
        std::stringstream ss;

        ss << "Monster Damage: ";
        ss << nwn_Get2daInt(dmg, "NumDice", ip->ip_cost_value);
        ss << 'd' << nwn_Get2daInt(dmg, "Die", ip->ip_cost_value);

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyDamageNone {
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
        return "No Damage";
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};


#endif // TALIB_ITEMPROP_DAMAGE_H
