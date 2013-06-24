#ifndef TALIB_ITEMPROP_INVALID_H
#define TALIB_ITEMPROP_INVALID_H

struct ItemPropertyInvalid {
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
        return "Invalid Property";
    }

    static void update(CNWItemProperty* ip,
                       int32_t version) {}
};

#endif // TALIB_ITEMPROP_INVALID_H
