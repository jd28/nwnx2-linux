#include "NWNXCombat.h"

extern CNWNXCombat combat;

int32_t Hook_GetArmorClass(CNWSCreature *cre) {
    auto c = combat.get_creature(cre->obj.obj_id);
    if ( !c ) { return 0; }

    return c->defense.getArmorClass(true, 0, false);
}
