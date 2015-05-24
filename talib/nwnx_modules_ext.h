#ifndef NWNX_MODULES_EXT_H_
#define NWNX_MODULES_EXT_H_

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
    int32_t  result;
} Event;

typedef struct {
    CNWSObject  *obj;
    CGameEffect *eff;
    bool         is_remove;
    bool         delete_eff;
} EventEffect;


#endif  // NWNX_MODULES_EXT_H_
