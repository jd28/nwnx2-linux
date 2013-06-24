#ifndef ITEM_PROPERTY_EXTRA_DAMAGE_H
#define ITEM_PROPERTY_EXTRA_DAMAGE_H

struct ItemPropertyExtraDamageMelee {
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
        return "ItemPropertyExtraDamageMelee";
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

struct ItemPropertyExtraDamageRanged {
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
        return "ItemPropertyExtraDamageRanged";
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // ITEM_PROPERTY_EXTRA_DAMAGE_H
