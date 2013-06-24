#ifndef TALIB_ITEMPROP_SAVING_THROW_H
#define TALIB_ITEMPROP_SAVING_THROW_H

struct ItemPropertySavingThrow {
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
        C2DA *tda = nwn_GetCached2da("iprp_savingthrow");
        if ( !tda ) { return std::string(""); }

        std::stringstream ss;

        ss << "Saving Throw Bonus: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unkown"; }

        ss << " +" << ip->ip_cost_value;
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertySavingThrowVs {
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
        C2DA *tda = nwn_GetCached2da("iprp_saveelement");
        if ( !tda ) { return std::string(""); }

        std::stringstream ss;

        ss << "Saving Throw Bonus: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unkown"; }

        ss << " +" << ip->ip_cost_value;
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertySavingThrowPenalty {
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
        C2DA *tda = nwn_GetCached2da("iprp_savingthrow");
        if ( !tda ) { return std::string(""); }

        std::stringstream ss;

        ss << "Saving Throw Penalty: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unkown"; }

        ss << " -" << ip->ip_cost_value;
	
        return ss.str();

    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertySavingThrowVsPenalty {
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
        C2DA *tda = nwn_GetCached2da("iprp_saveelement");
        if ( !tda ) { return std::string(""); }

        std::stringstream ss;

        ss << "Saving Throw Penalty: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(tda, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unkown"; }

        ss << " -" << ip->ip_cost_value;
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_SAVING_THROW_H
