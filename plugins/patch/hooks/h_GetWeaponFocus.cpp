#include "NWNXPatch.h"

extern CNWNXPatch patch;

int Hook_GetWeaponFocus(CNWSCreatureStats *stats, CNWSItem *it) {
    if ( it && it->it_baseitem == BASE_ITEM_TRIDENT ) {
        return CNWSCreatureStats__HasFeat(stats, FEAT_WEAPON_FOCUS_TRIDENT);
    }
    return CNWSCreatureStats__GetWeaponFocusNext(stats, it);
}
