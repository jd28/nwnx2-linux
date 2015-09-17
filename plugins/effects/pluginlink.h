#pragma once

struct EffectsCustomEvent {
    /* The object on which the effect is applied/removed. */
    CNWSObject  *object;
    /* The effect itself. */
    CGameEffect *effect;
    /* Return true here if the effect cant be applied; this deletes it. */
    bool         failed;
};

/**
 * Event: EVENT_EFFECTS_CUSTOM_APPLY
 * Param: EffectsCustomEvent
 */
#define EVENT_EFFECTS_CUSTOM_APPLY "Effects/Custom/Apply"

/**
 * Event: EVENT_EFFECTS_CUSTOM_REMOVE
 * Param: EffectsCustomEvent
 */
#define EVENT_EFFECTS_CUSTOM_REMOVE "Effects/Custom/Remove"

struct EffectsItempropEvent {
    CNWSCreature    *obj;
    CNWSItem        *item;
    CNWItemProperty *ip;
    uint32_t         slot;
    bool             suppress;
    bool             remove;
};

/**
 * Event: EVENT_EFFECTS_IP_APPLY
 * Param: EffectsItempropEvent
 */
#define EVENT_EFFECTS_IP_APPLY "Effects/IP/Apply"

/**
 * Event: EVENT_EFFECTS_IP_REMOVE
 * Param: EffectsItempropEvent
 */
#define EVENT_EFFECTS_IP_REMOVE "Effects/IP/Remove"
