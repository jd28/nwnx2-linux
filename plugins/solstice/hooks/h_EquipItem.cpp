#include "NWNXCombat.h"

extern CNWNXCombat combat;

int32_t Hook_EquipItem(CNWSCreature *cre, uint32_t a, CNWSItem *it, int32_t b, int32_t c) {
    int32_t result = CNWSCreature__EquipItem_orig(cre, a, it, b, c);

    auto cr = combat.get_creature(cre->obj.obj_id);
    if ( cr ) { cr->update(); }
    
    return result;
}
