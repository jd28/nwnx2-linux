#ifndef TALIB_ITEMPROP_BONUS_SPELL_SLOT_H
#define TALIB_ITEMPROP_BONUS_SPELL_SLOT_H

struct ItemPropertyBonusSpellSlot {
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
        C2DA *tda = nwn_GetCached2da("classes");
        if ( !tda ) { return std::string(""); }

        std::stringstream ss;

        ss << "Spell Slot: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unkown"; }

        ss << " Level: " << ip->ip_cost_value;

        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_BONUS_SPELL_SLOT_H
