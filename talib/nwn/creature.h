#ifndef TALIB_CREATURE_H
#define TALIB_CREATURE_H

CNWSCreature *nwn_GetCreatureByID(uint32_t oid);

void      nwn_ActionUseItem(CNWSCreature *cre, CNWSItem* it, CNWSObject *target, CNWSArea* area, CScriptLocation *loc, int prop);
void      nwn_AddKnownFeat(CNWSCreature *cre, uint16_t feat, uint32_t level);
int       nwn_AddKnownSpell(CNWSCreature *cre, uint32_t sp_class, uint32_t sp_id, uint32_t sp_level);
uint32_t  nwn_CalculateSpellDC(CNWSCreature *cre, uint32_t spellid);
bool      nwn_CanUseSkill(CNWSCreature* cre, uint8_t skill);
void      nwn_DecrementFeatRemainingUses(CNWSCreatureStats *stats, uint16_t feat);
int8_t    nwn_GetAbilityModifier(CNWSCreatureStats *stats, int8_t abil, bool armorcheck);
int       nwn_GetAttacksPerRound(CNWSCreatureStats *stats);
int8_t    nwn_GetBaseSavingThrow(CNWSCreature *cre, uint32_t type);
int       nwn_GetBonusSpellSlots(CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level);
int       nwn_GetCriticalHitMultiplier(CNWSCreatureStats *stats, bool offhand);
int       nwn_GetCriticalHitRange(CNWSCreatureStats *stats, bool offhand);
uint16_t  nwn_GetDamageFlags(CNWSCreature *cre);
int32_t   nwn_GetDexMod(CNWSCreatureStats *stats, bool armor_check);
bool      nwn_GetEffectImmunity(CNWSCreature *cre, int type, CNWSCreature *vs);
int       nwn_GetFeatRemainingUses(CNWSCreatureStats *stats, uint16_t feat);
bool      nwn_GetFlanked(CNWSCreature *cre, CNWSCreature *target);
bool      nwn_GetFlatFooted(CNWSCreature *cre);
int       nwn_GetKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx);
bool      nwn_GetKnowsSpell(CNWSCreature *cre, uint32_t sp_class, uint32_t sp_id);
bool      nwn_GetHasFeat(CNWSCreatureStats *stats, uint16_t feat);
int32_t   nwn_GetHasNthFeat(CNWSCreature *cre, uint16_t start, uint16_t stop);
uint32_t  nwn_GetHitDice(CNWSCreature *cre);
bool      nwn_GetIsInvisible(CNWSCreature *cre, CNWSObject *obj);
bool      nwn_GetIsVisible(CNWSCreature *cre, nwn_objid_t target);
CNWSItem *nwn_GetItemInSlot(CNWSCreature *cre, uint32_t slot);
double    nwn_GetMaxAttackRange(CNWSCreature *cre, nwn_objid_t target);
int       nwn_GetMaxSpellSlots (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level);
int       nwn_GetMemorizedSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx);
int       nwn_GetRelativeWeaponSize(CNWSCreature *cre, CNWSItem *weapon);
int       nwn_GetRemainingSpellSlots (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level);
int8_t    nwn_GetSkillRank(CNWSCreature *cre, uint8_t skill, CNWSObject *vs, bool base);
int       nwn_GetTotalFeatUses(CNWSCreatureStats *stats, uint16_t feat);
int       nwn_GetTotalKnownSpells (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level);
int       nwn_GetTotalNegativeLevels(CNWSCreatureStats *stats);
void      nwn_JumpToLimbo(CNWSCreature *cre);
void      nwn_NotifyAssociateActionToggle(CNWSCreature *cre, int32_t mode);
int       nwn_RecalculateDexModifier(CNWSCreatureStats *stats);
int       nwn_RemoveKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_id);
int       nwn_ReplaceKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_id, uint32_t sp_new);
void      nwn_ResolveItemCastSpell(CNWSCreature *cre, CNWSObject *target);
void      nwn_ResolveSafeProjectile(CNWSCreature *cre, uint32_t delay, int attack_num);
uint8_t   nwn_SetAbilityScore(CNWSCreatureStats *stats, int abil, int val);
void      nwn_SetActivity(CNWSCreature *cre, int32_t a, int32_t b);
void      nwn_SetAnimation(CNWSCreature *cre, uint32_t anim);
void      nwn_SetCombatMode(CNWSCreature *cre, uint8_t mode);
int       nwn_SetKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx, uint32_t sp_id);
int       nwn_SetMemorizedSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx, uint32_t sp_spell, uint32_t sp_meta, uint32_t sp_flags);
int       nwn_SetRemainingSpellSlots (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_slots);
void      nwn_SendMessage(uint32_t mode, uint32_t id, const char *msg, uint32_t to);

#endif // TALIB_CREATURE_H