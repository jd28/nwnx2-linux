#ifndef TALIB_ITEMPROP_TRAP_H
#define TALIB_ITEMPROP_TRAP_H

struct ItemPropertyTrap {
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
        C2DA *tda = nwn_GetCached2da("iprp_traps");
        C2DA *tda_cost = nwn_GetCached2da("iprp_trapcost");
        if ( !tda || !tda_cost ) { return std::string(""); }

        std::stringstream ss;

        ss << "Trap: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unknown"; }

        ss << ' ';

        s = nwn_GetStringByStrref(nwn_Get2daInt(tda_cost, "Name", ip->ip_cost_value));
        if (s) { ss << s; free(s); }
        else { ss << "Unknown"; }
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_TRAP_H
