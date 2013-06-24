#ifndef TALIB_ITEMPROP_SPELL_RESISTANCE_H
#define TALIB_ITEMPROP_SPELL_RESISTANCE_H

struct ItemPropertySpellResistance {
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

        ss << "Spell Resistance: ";
        ss << nwn_Get2daInt(dmg, "Value", ip->ip_cost_value);

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_SPELL_RESISTANCE_H
