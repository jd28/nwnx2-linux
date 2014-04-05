#include "NWNXCombat.h"

extern CNWNXCombat combat;

void Hook_ResolveDamageShields(CNWSCreature *target, CNWSCreature *attacker) {
    for ( size_t i = target->cre_stats->cs_first_dmgshield_eff;
          i < target->obj.obj_effects_len; ++i ) {
        CGameEffect *eff = target->obj.obj_effects[i];
        if ( eff->eff_type != EFFECT_TRUETYPE_DAMAGE_SHIELD ) {
            break;
        }

        int amt = eff->eff_integers[0];
        DiceRoll randamt = combat.ip_dmg_to_roll(eff->eff_integers[1]);
        int type = eff->eff_integers[2];
                
        amt += randamt.roll();
                
        CGameEffect *eff_dmg = effect_damage(amt, type, 0);
        eff_dmg->eff_creator = target->obj.obj_id;
        nwn_SetDurationType(eff_dmg, DURATION_TYPE_INSTANT);
        CNWSObject__ApplyEffect(&attacker->obj, eff_dmg, 0, 0);

        int vfx = nwn_GetDamageVisualEffect(type, false);
        if ( vfx > 0 ) {
            CGameEffect *eff_vfx = effect_visual(vfx, false);
            eff_dmg->eff_creator = target->obj.obj_id;
            nwn_SetDurationType(eff_vfx, DURATION_TYPE_INSTANT);
            CNWSObject__ApplyEffect(&attacker->obj, eff_vfx, 0, 0);                             
        }
    }
}
