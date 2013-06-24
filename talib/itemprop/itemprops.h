#include <string>
#include <vector>
#include <functional>
#include <utility>

#include "NWNXLib.h"

struct ItemPropertyDispatch {
    typedef int32_t (*ApplyRemoveFunc)(CNWItemProperty* ip, 
                                       CNWSItem *item,
                                       CNWSCreature *cre,
                                       int32_t version);
    typedef int32_t (*CostFunc)(CNWItemProperty* ip,
                                int32_t version);
    typedef std::string (*ToStringFunc)(CNWItemProperty* ip,
                                        int32_t version);
    typedef void (*UpdateFunc)(CNWItemProperty* ip,
                               int32_t version);

    ApplyRemoveFunc  apply;          
    CostFunc         getCost;
    ApplyRemoveFunc  remove;
    ToStringFunc     toString;
    UpdateFunc       update;
};

class ItemProperties {
    static std::vector<ItemPropertyDispatch> itemprops_;
    static const ItemPropertyDispatch invalid_;

public:
    static std::pair<bool, int32_t> apply(CNWItemProperty* ip, 
                         CNWSItem *item, 
                         CNWSCreature *cre,
                         int32_t version = 0);

    static std::pair<bool, int32_t> getCost(CNWItemProperty* ip,
                           int32_t version = 0);

    static std::pair<bool, int32_t> remove(CNWItemProperty* ip, 
                          CNWSItem *item, 
                          CNWSCreature *cre,
                          int32_t version = 0);

    static std::pair<bool, std::string> toString(CNWItemProperty* ip,
                                int32_t version = 0);

    static bool update(CNWItemProperty* ip,
                       int32_t version = 0);
};

