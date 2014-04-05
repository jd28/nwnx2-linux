CNWSCombatAttackData *nwn_GetAttack(CNWSCreature *cre, int32_t attack) {
    return CNWSCombatRound__GetAttack(cre->cre_combat_round, attack);
}

CNWSItem *nwn_GetCurrentAttackWeapon(CNWSCreature *cre, int32_t attack_type) {
    return CNWSCombatRound__GetCurrentAttackWeapon(cre->cre_combat_round, attack_type);
}

int32_t nwn_GetWeaponAttackType(CNWSCreature *cre) {
    return CNWSCombatRound__GetWeaponAttackType(cre->cre_combat_round);
}

void nwn_ResolveCachedSpecialAttacks(CNWSCreature *cre) {
    CNWSCreature__ResolveCachedSpecialAttacks(cre);
}

void nwn_ResolveMeleeAnimations(CNWSCreature *attacker, int32_t i, int32_t attack_count,
                                CNWSObject *target, int32_t anim) {
    CNWSCreature__ResolveMeleeAnimations(attacker, i, attack_count, target, anim);
}

void nwn_ResolveRangedAnimations(CNWSCreature *attacker, CNWSObject *target,
                                 int32_t anim) {
    CNWSCreature__ResolveRangedAnimations(attacker, target, anim);
}

void nwn_ResolveRangedMiss(CNWSCreature *attacker, CNWSObject *target) {
    CNWSCreature__ResolveRangedMiss(attacker, target);
}

void nwn_SignalMeleeDamage(CNWSCreature *cre, CNWSObject *target, uint32_t attack_count) {
    CNWSCreature__SignalMeleeDamage(cre, target, attack_count);
}


void nwn_SignalRangedDamage(CNWSCreature *cre, CNWSObject *target, int32_t attack_count) {
    CNWSCreature__SignalRangedDamage(cre, target, attack_count);
}

void nwn_AddOnHitEffect(CNWSCreature *cre, CGameEffect *eff) {
    auto cur = cre->cre_combat_round->cr_current_attack;
    CNWSCombatAttackData *attack = nwn_GetAttack(cre, cur);
    if ( attack == NULL || eff == NULL ) return;
    int res = CExoArrayList_ptr_add(&attack->cad_onhit_effs, eff);
}

void nwn_AddCombatMessageData(CNWSCombatAttackData *attack, int32_t type, int32_t num_obj, uint32_t obj1, uint32_t obj2,
                              int32_t num_int, int32_t int1, int32_t int2, int32_t int3, int32_t int4) {
    CNWCCMessageData *msg = CNWCCMessageData_create();
    if (type) {
        msg->type = type;
    }

    switch (num_obj) {
    default: break;
    case 2:
        CExoArrayList_uint32_add(&msg->objects, obj1);
        CExoArrayList_uint32_add(&msg->objects, obj2);
    case 1:
        CExoArrayList_uint32_add(&msg->objects, obj1);
        break;
    }

    switch (num_int) {
    default: break;
    case 4:
        CExoArrayList_int32_add(&msg->integers, int1);
        CExoArrayList_int32_add(&msg->integers, int2);
        CExoArrayList_int32_add(&msg->integers, int3);
        CExoArrayList_int32_add(&msg->integers, int4);
        break;
    case 3:
        CExoArrayList_int32_add(&msg->integers, int1);
        CExoArrayList_int32_add(&msg->integers, int2);
        CExoArrayList_int32_add(&msg->integers, int3);
        break;
    case 2:
        CExoArrayList_int32_add(&msg->integers, int1);
        CExoArrayList_int32_add(&msg->integers, int2);
        break;
    case 1:
        CExoArrayList_int32_add(&msg->integers, int1);
        break;
    }

    CExoArrayList_ptr_add(&attack->cad_feedback, msg);
}

void nwn_AddCircleKickAttack(CNWSCreature *cre, uint32_t target) {
    CNWSCombatRound__AddCircleKickAttack(cre->cre_combat_round, target);
}

void nwn_AddCleaveAttack(CNWSCreature *cre, uint32_t target, bool great) {
    CNWSCombatRound__AddCleaveAttack(cre->cre_combat_round, target, great);
}

void nwn_ResolveOnHitEffect(CNWSCreature *cre, CNWSObject* target, bool offhand,
                            bool critical) {
    CNWSCreature__ResolveOnHitEffect(cre, target, offhand, critical);
}
