#ifndef TALIB_ITEMPROP_ARCANE_SPELL_FAILURE_H
#define TALIB_ITEMPROP_ARCANE_SPELL_FAILURE_H

struct ItemPropertyArcaneSpellFailure {
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
        C2DA *dmg = nwn_GetCached2da("iprp_arcspell");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "Arcane Spell Failure: ";
        int32_t val = nwn_Get2daInt(dmg, "Value", ip->ip_cost_value);
        if ( val > 0 ) { ss << '+'; }
        ss << val;

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_ARCANE_SPELL_FAILURE_H
