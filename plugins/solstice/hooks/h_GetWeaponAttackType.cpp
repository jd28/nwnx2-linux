#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;

// The following code does not mimic the NWN engine...
// It will never return ATTACK_TYPE_EXTRA1 or ATTACK_TYPE_EXTRA2
int32_t Hook_GetWeaponAttackType(CNWSSolsticeRound *cr) {
    int on         = cr->cr_onhand_atks;
    int off        = cr->cr_offhand_atks;
    int additional = cr->cr_additional_atks;
    int effect     = cr->cr_effect_atks;
    int next       = cr->cr_current_attack + 1;

    auto c = solstice.get_creature(cr->cr_original->obj.obj_id);

    // Note that use_cre_attacks is true IFF there is no
    // onhand and offhand weapon.
    if ( c->offense.hasCreatureAttacks() ) {
        switch ( true_random(1, 3) ) {
        case 1:
            if ( c->offense.isEquipValid(3) ) {
                return ATTACK_TYPE_CWEAPON1;
            }
        case 2:
            if ( c->offense.isEquipValid(4) ) {
                return ATTACK_TYPE_CWEAPON2;
            }
        case 3:
            if ( c->offense.isEquipValid(5) ) {
                return ATTACK_TYPE_CWEAPON3;
            }
        }

        // If chanced on a invalid creature attack...
        // take the first one found.
        for ( int i = 3; i < EQUIP_TYPE_NUM; ++i ) {
            if ( c->offense.isEquipValid(i) ) {
                return i;
            }
        }
    }

    if ( off > 0 && next > (on + additional + effect) ) {
        return ATTACK_TYPE_OFFHAND;
    }
    else if ( c->offense.isEquipValid(0) ) {
        return ATTACK_TYPE_ONHAND;
    }
    else {
        return ATTACK_TYPE_UNARMED;
    }
}
