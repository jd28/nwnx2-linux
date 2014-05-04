#ifndef TALIB_NWN_COMBAT_H
#define TALIB_NWN_COMBAT_H

void nwn_AddCombatMessageData(
    CNWSCombatAttackData *attack, int32_t type, int32_t num_obj, uint32_t obj1, uint32_t obj2,
    int32_t num_int, int32_t int1, int32_t int2, int32_t int3, int32_t int4,
    const char* str);

void nwn_AddOnHitEffect(CNWSCreature *cre, CGameEffect *eff);
CNWSCombatAttackData *nwn_GetAttack(CNWSCreature *cre, int32_t attack);
CNWSItem *nwn_GetCurrentAttackWeapon(CNWSCreature *cre, int32_t attack_type);
int32_t nwn_GetWeaponAttackType(CNWSCreature *cre);
void nwn_ResolveCachedSpecialAttacks(CNWSCreature *cre);
void nwn_ResolveMeleeAnimations(CNWSCreature *attacker, int32_t i, int32_t attack_count,
                                CNWSObject *target, int32_t anim);
void nwn_ResolveRangedAnimations(CNWSCreature *attacker, CNWSObject *target,
                                 int32_t anim);
void nwn_ResolveRangedMiss(CNWSCreature *attacker, CNWSObject *target);
void nwn_SignalMeleeDamage(CNWSCreature *cre, CNWSObject *target, uint32_t attack_count);
void nwn_SignalRangedDamage(CNWSCreature *cre, CNWSObject *target, int32_t attack_count);

void nwn_AddCircleKickAttack(CNWSCreature *cre, uint32_t target);
void nwn_AddCleaveAttack(CNWSCreature *cre, uint32_t target, bool great);

void nwn_ResolveOnHitEffect(CNWSCreature *cre, CNWSObject* target, bool offhand,
                            bool critical);
void nwn_ApplyOnHitDeathAttack(CNWSCreature *cre, CNWSObject *target, int32_t dc);

#endif // TALIB_NWN_COMBAT_H
