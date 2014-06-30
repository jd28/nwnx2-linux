#ifndef NWNX_MODULES_EXT_H_
#define NWNX_MODULES_EXT_H_

typedef struct {
    const char* msg;
    uint32_t to;
    uint32_t from;
    uint8_t channel;
    bool suppress;
} ChatMessage;

typedef struct {
    int type;
    int subtype;
    uint32_t to;
    void *msg_data;
    bool suppress;
} CombatMessage;

typedef struct {
    CNWSObject  *obj;
    CGameEffect *effect;
    bool is_remove; // exists if one wanted to have apply/remove be the same...
    bool delete_eff;
} CustomEffect;

typedef struct {
    int      type;
    int      subtype;
    uint32_t object;
    uint32_t target;
    uint32_t item;
    Vector   loc;
    bool     bypass;
    bool     use_result;
    int32_t  result;
} Event;


typedef struct {
    int      type;
    uint32_t object;
    uint32_t item;
    bool     use_result;
    uint32_t  result;
} EquipEvent;

typedef struct {
    CNWSObject  *obj;
    CGameEffect *eff;
    bool         is_remove;
    bool         delete_eff;
} EventEffect;

typedef struct {
    CNWSCreature    *obj;
    CNWSItem        *item;
    CNWItemProperty *ip;
    uint32_t         slot;
    bool             suppress;
    bool             remove;
} EventItemprop;

typedef struct {
    CNWMessage *msg;
    CNWSPlayer *pc;
    uint32_t    obj;
    uint32_t    type;
    bool        bypass;
    int32_t     result;
} EventExamine;

#endif  // NWNX_MODULES_EXT_H_
