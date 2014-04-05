#include "NWNXCombat.h"

extern CNWNXCombat combat;

int32_t Hook_UnequipItem(CNWSCreature *cre, CNWSItem *it, int32_t a) {
    int32_t res = CNWSCreature__UnequipItem_orig(cre, it, a);

    if ( res ) {
        auto c = combat.get_creature(cre->obj.obj_id);
        if ( c ) { c->update(); }
    }

    return res;
}
