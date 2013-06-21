#ifndef _NX_NWN_STRUCT_CNWSOBJECTACTIONNODE_
#define _NX_NWN_STRUCT_CNWSOBJECTACTIONNODE_

struct CNWSObjectActionNode_s {
    uint32_t action_id;
    uint32_t param_type[12];
    void *param[12];
    uint32_t group_action_id;
    uint32_t params;
    uint32_t field_68;
};

#endif
