#ifndef TALIB_ITEMPROP_ONHIT_MONSTER_H
#define TALIB_ITEMPROP_ONHIT_MONSTER_H

struct ItemPropertyOnMonsterHit {
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
        C2DA *dmg = nwn_GetCached2da("iprp_monsterhit");
        if ( dmg == NULL ) { return std::string(""); }

        std::stringstream ss;

        ss << "On Hit: Monster: ";
        char *s = nwn_GetStringByStrref(nwn_Get2daInt(dmg, "Name", ip->ip_subtype));
        if (s) { ss << s; free(s); }
        else { ss << "Unknown"; }
	
        return ss.str();
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_ONHIT_MONSTER_H
