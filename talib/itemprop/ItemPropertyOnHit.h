#ifndef TALIB_ITEMPROP_ONHIT_H
#define TALIB_ITEMPROP_ONHIT_H

struct ItemPropertyOnHit {
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
        C2DA *tda = (*NWN_Rules)->ru_2das->tda_iprp_onhit;
        C2DA *tda_cost = nwn_GetCached2da("iprp_onhitcost");
        if ( !tda_cost ) { return std::string(""); }

        std::stringstream ss;

        ss << "On Hit: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unknown"; }

        ss << " DC: " << nwn_Get2daInt(tda, "Value", ip->ip_cost_value);
        ss << " Chance: " << ip->ip_chance << '%';
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_ONHIT_H
