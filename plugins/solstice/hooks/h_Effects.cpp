#include "NWNXSolstice.h"
#include "hooks.h"

extern CNWNXSolstice solstice;

int32_t Hook_OnApplyDamageImmunityDecrease(
    CNWSEffectListHandler *elh,
    CNWSObject *obj,
    CGameEffect *eff,
    int32_t a)
{
    int32_t res = CNWSEffectListHandler__OnApplyDamageImmunityDecrease_orig(elh, obj, eff, a);
    int32_t idx = ns_BitScanFFS(eff->eff_integers[0]);

    if ( res == 0 && idx >= 0 && idx < DAMAGE_INDEX_NUM && res == 0 && obj->obj_type == 5) {
        auto cre = Local_GetCreature(obj->obj_id);
        if (cre) {
            cre->info.defense.immunity[idx] -= eff->eff_integers[1];
        }
    }

    return res;
}

int32_t Hook_OnApplyDamageImmunityIncrease(
    CNWSEffectListHandler *elh,
    CNWSObject *obj,
    CGameEffect *eff,
    int32_t a)
{
    int32_t res = CNWSEffectListHandler__OnApplyDamageImmunityIncrease_orig(elh, obj, eff, a);

    int32_t idx = ns_BitScanFFS(eff->eff_integers[0]);

    if ( res == 0 && idx >= 0 && idx < DAMAGE_INDEX_NUM && res == 0 && obj->obj_type == 5) {
        auto cre = Local_GetCreature(obj->obj_id);
        if (cre) {
            cre->info.defense.immunity[idx] += eff->eff_integers[1];
        }
    }

    return res;
}

int32_t Hook_OnRemoveDamageImmunityIncrease(
    CNWSEffectListHandler *elh,
    CNWSObject *obj,
    CGameEffect *eff)
{
    int32_t res = CNWSEffectListHandler__OnRemoveDamageImmunityIncrease_orig(elh, obj, eff);

    int32_t idx = ns_BitScanFFS(eff->eff_integers[0]);

    if ( idx >= 0 && idx < DAMAGE_INDEX_NUM && obj->obj_type == 5) {
        auto cre = Local_GetCreature(obj->obj_id);
        if (cre) {
            cre->info.defense.immunity[idx] -= eff->eff_integers[1];
        }
    }

    return res;
}

int32_t Hook_OnRemoveDamageImmunityDecrease(
    CNWSEffectListHandler *elh,
    CNWSObject *obj,
    CGameEffect *eff)
{
    int32_t res = CNWSEffectListHandler__OnRemoveDamageImmunityDecrease_orig(elh, obj, eff);

    int32_t idx = ns_BitScanFFS(eff->eff_integers[0]);

    if ( idx >= 0 && idx < DAMAGE_INDEX_NUM && obj->obj_type == 5) {
        auto cre = Local_GetCreature(obj->obj_id);
        if (cre) {
            cre->info.defense.immunity[idx] += eff->eff_integers[1];
        }
    }

    return res;
}
