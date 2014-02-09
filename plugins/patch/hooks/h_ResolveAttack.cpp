#include "NWNXPatch.h"

extern CNWNXPatch patch;

void Hook_ResolveAttack(CNWSCreature *cre, uint32_t target, int32_t b, int32_t c) {
    nwn_objid_t target_prev = cre->cre_attack_target;
    int32_t kicks = cre->cre_combat_round->cr_num_circle_kicks;

    patch.Log(3, "Target: %x, Previous Target: %x\n", target, target_prev);
    
    patch.Log(3, "Kicks before: %d\n", kicks);
    CNWSCreature__ResolveAttackNext(cre, target, b, c);
    patch.Log(3, "Kicks after: %d\n", 
              cre->cre_combat_round->cr_num_circle_kicks);
    
    if ( cre->cre_combat_round->cr_num_circle_kicks == 0 &&
         target_prev != OBJECT_INVALID                   &&
         target_prev != target ) {
        CNWSObject *ob = (CNWSObject*)nwn_GetObjectByID(target_prev);
        if ( ob != NULL && !CNWSObject__GetDead(ob) ) {
            CNWSObjectActionNode *action = (CNWSObjectActionNode*)cre->obj.obj_ai_action;
            if ( action ) {
                patch.Log(3, "Circle Kick: Reseting Target: %x\n", target_prev);
                action->param[0] = (void*)target_prev;
            }
        }
    }
}
