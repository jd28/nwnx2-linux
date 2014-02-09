#include "NWNXPatch.h"

extern CNWNXPatch patch;

static uint32_t GetDurationType(CGameEffect *eff) {
    return eff->eff_dursubtype & 0x7;
}

int Hook_OnApplyAbilityDecrease(CNWSEffectListHandler *h, CNWSObject *obj,
                                CGameEffect *eff, int32_t a) {
    if ( GetDurationType(eff) == 3 || eff->field_04 == 333 ) {
        eff->field_04 = 0;
        int prev = patch.override_immunity;
        patch.override_immunity = 32;
        int ret = CNWSEffectListHandler__OnApplyAbilityDecreaseNext(h, obj, eff, a);
        patch.override_immunity = prev;
        return ret;
    }
    return CNWSEffectListHandler__OnApplyAbilityDecreaseNext(h, obj, eff, a);
}
