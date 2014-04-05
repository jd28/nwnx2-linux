#include "NWNXCombat.h"

extern CNWNXCombat combat;

int32_t Hook_DoDamageResistance(CNWSObject *obj, CNWSCreature *vs, int32_t amount,
                                uint16_t flags, int32_t no_feedback, int32_t from_attack,
                                int32_t a) {

    if ( !obj ) { return amount; }

    int32_t adj = 0;
    Creature *c;
    if ( obj->obj_type == OBJECT_TYPE_CREATURE &&
         (c = combat.get_creature(obj->obj_id)) ) {
        adj = c->defense.doDamageResistance(vs, amount, flags, no_feedback);
    }
    else { 
        SituatedObject ob(obj);
        adj = ob.doDamageResistance(vs, amount, flags, no_feedback);
    }

    return amount - adj;
}
