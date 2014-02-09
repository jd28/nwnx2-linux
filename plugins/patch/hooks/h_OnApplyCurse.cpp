#include "NWNXPatch.h"

extern CNWNXPatch patch;

int Hook_OnApplyCurse(CNWSEffectListHandler *h, CNWSObject *obj, CGameEffect *eff, int32_t a) {

    //DnD rules or Very high difficulty
    uint32_t diff = (*NWN_AppManager)->app_server->srv_internal->srv_info->sri_game_difficulty;
    patch.Log(3, "OnApplyCurse: Server Difficulty Level: %d\n", diff);
    if ( diff > 2) {
        int prev = patch.override_immunity;
        patch.override_immunity = 32;
        eff->field_04 = 333;
        int ret = CNWSEffectListHandler__OnApplyCurseNext(h, obj, eff, a);
        patch.override_immunity = prev;
        return ret;
    }

    return CNWSEffectListHandler__OnApplyCurseNext(h, obj, eff, a);
}
