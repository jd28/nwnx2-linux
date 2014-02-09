#include "NWNXPatch.h"

extern CNWNXPatch patch;

int Hook_GetEffectImmunity(CNWSCreatureStats *stats, uint8_t imm, CNWSCreature *vs) {
    if ( patch.override_immunity == 32 && imm == IMMUNITY_TYPE_ABILITY_DECREASE ) {
        return 0;
    }
    return CNWSCreatureStats__GetEffectImmunityNext(stats, imm, vs);
}
