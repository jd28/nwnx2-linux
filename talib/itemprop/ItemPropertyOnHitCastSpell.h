#ifndef TALIB_ITEMPROP_ONHIT_CAST_SPELL_H
#define TALIB_ITEMPROP_ONHIT_CAST_SPELL_H

struct ItemPropertyOnHitCastSpell {
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
        C2DA *dmg = (*NWN_Rules)->ru_2das->tda_iprp_onhitspell;
        std::stringstream ss;

        ss << "On Hit: Cast Spell: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(dmg, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unknown"; }

        ss << " Level: " << ip->ip_cost_value + 1;
        ss << " Chance: " << ip->ip_chance << '%';
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_ONHIT_CAST_SPELL_H
