#pragma once

#include <stdint.h>
#include "../typedef.h"

#define EVENT_ITEMS_INFO "Items/Info"
typedef struct {
    int       type;
    nwobjid   object;
    nwobjid   item;
    bool      use_result;
    uint32_t  result;
} ItemsInfoEvent;

#define EVENT_ITEMS_PROPERTY "Items/Property"
typedef struct {
    CNWSCreature    *obj;
    CNWSItem        *item;
    CNWItemProperty *ip;
    uint32_t         slot;
    bool             suppress;
    bool             remove;
} ItemsPropertyEvent;
