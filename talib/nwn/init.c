#include "NWNXLib.h"

#define SET(nm, addr)                           \
    if ( nm == NULL ) *(int*)& nm = addr

void talib_init() {

    SET(CGameEffect__dtor, 0x0817DFDC);

    SET(CNWSArea__ClearLineOfSight, 0x080d31f0);

    SET(CNWSObject__ApplyEffect, 0x081CE7D8);
    SET(CNWSObject__RemoveEffectById, 0x081CEEA0);

    SET(CNWVirtualMachineCommands__ExecuteCommand, 0x08231A34);
    SET(CVirtualMachine__StackPopEngineStructure, 0x08262CFC);
    SET(CVirtualMachine__StackPopFloat, 0x08262AD8);
    SET(CVirtualMachine__StackPopInteger, 0x082629FC);
    SET(CVirtualMachine__StackPopObject, 0x08262DFC);
    SET(CVirtualMachine__StackPopString, 0x08262C18);
    SET(CVirtualMachine__StackPopVector, 0x082643C8);

    SET(CVirtualMachine__StackPushInteger, 0x0826434C);
    SET(CVirtualMachine__StackPushFloat, 0x08264388);
    SET(CVirtualMachine__StackPushString, 0x08264430);
    SET(CVirtualMachine__StackPushVector, 0x08262B98);
    SET(CVirtualMachine__StackPushObject, 0x08264514);
    SET(CVirtualMachine__StackPushEngineStructure, 0x082644AC);

    SET(CTwoDimArrays__GetCached2DA, 0x080B92A8);
    SET(C2DA__GetCExoStringEntry,    0x082BD0D4);
    SET(C2DA__GetCExoStringEntry2,   0x082BEDBC);
    SET(C2DA__GetFLOATEntry,         0x082BF100);
    SET(C2DA__GetFLOATEntry2,        0x082BEFA4);
    SET(C2DA__GetINTEntry,           0x082BDA04);
    SET(C2DA__GetINTEntry2,          0x082BD77C);
    SET(C2DA__GetNumColumns,         0x082BF6D0);
    SET(C2DA__GetNumRows,            0x082BF6DC);

	SET(CGameEffect__ctor, 0x0817DC70);
    SET(CGameEffect__SetLinked, 0x0817F750);
    SET(CGameEffect__SetNumIntegers, 0x0817F54C);
    SET(CGameEffect__SetString, 0x0817F6A4);
    SET(CGameEffect__UpdateLinked, 0x0817E57C);

    SET(CItemRepository__AddItem,                   0x081A32D0);
    SET(CItemRepository__FindItemWithBaseItemId,    0x081A3EE4);

    SET(CNWCCMessageData__ctor,                     0x080C1B6C);
    SET(CNWCCMessageData__CopyTo,                   0x080c212c);

    SET(CNWSCombatRound__AddAttackOfOpportunity,    0x080E31E0);
    SET(CNWSCombatRound__AddCircleKickAttack,       0x080e2f94);
    SET(CNWSCombatRound__AddCleaveAttack,           0x080e2e4c);
    SET(CNWSCombatRound__AddParryAttack,            0x080E2BE4);
    SET(CNWSCombatRound__AddParryIndex,             0x080E2D40);
    SET(CNWSCombatRound__CalculateOffHandAttacks,   0x080E1D50);
    SET(CNWSCombatRound__GetAttack,                 0x080e522c);
    SET(CNWSCombatRound__GetTotalAttacks,           0x080e5534);
    SET(CNWSCombatRound__GetWeaponAttackType,       0x080E38DC);
    SET(CNWSCombatRound__SetPauseTimer,             0x080E4E78);
    SET(CNWSCombatRound__SetRoundPaused,            0x080E4DF8);

    SET(CNWSCreature__ApplyOnHitDeathAttack,        0x080f34d8);
    SET(CNWSCreature__CalculateProjectileTimeToTarget, 0x080F5B98);
    SET(CNWSCreature__CalculateSpellSaveDC,         0x0813ADC8);
    SET(CNWSCreature__CanEquipItem,                 0x080FF978);
    SET(CNWSCreature__CanUseItem,                   0x08110df8);
    SET(CNWSCreature__EquipItem,                    0x0811B64C);
    SET(CNWSCreature__GetAssociateId,               0x0810f9b4);
    SET(CNWSCreature__GetDamageFlags,               0x0813C760);
    SET(CNWSCreature__GetBlind,                     0x0813D060);
    SET(CNWSCreature__GetFlanked,                   0x080F1928);
    SET(CNWSCreature__GetFlatFooted,                0x080F1830);
    SET(CNWSCreature__GetInvisible,                 0x08136F94);
    SET(CNWSCreature__GetIsPossessedFamiliar,       0x08113574);
    SET(CNWSCreature__MaxAttackRange,               0x0813c114);
    SET(CNWSCreature__GetNearestEnemy,              0x0812c188);
    SET(CNWSCreature__GetVisibleListElement,        0x081131fc);
    SET(CNWSCreature__MaxAttackRange,               0x0813C114);
    SET(CNWSCreature__NotifyAssociateActionToggle,  0x0813B454);
    SET(CNWSCreature__ReceiveAssociateCommand,      0x0810cdc0);
    SET(CNWSCreature__RemoveItemFromRepository,     0x0813B22C);
    SET(CNWSCreature__ResolveCachedSpecialAttacks,  0x080EC390);
    SET(CNWSCreature__ResolveItemCastSpell,         0x080ECB18);
    SET(CNWSCreature__ResolveMeleeAnimations,       0x080EAA18);
    SET(CNWSCreature__ResolveOnHitEffect,           0x080EE6C0);
    SET(CNWSCreature__ResolveOnHitVisuals,          0x080ee4d4);
    SET(CNWSCreature__ResolveRangedAnimations,      0x080E7FE8);
    SET(CNWSCreature__ResolveRangedMiss,            0x080E8530);
    SET(CNWSCreature__SavingThrowRoll,              0x080f0a90);
    SET(CNWSCreature__SendFeedbackMessage,          0x0813533C);
    SET(CNWSCreature__SetActivity,                  0x081152E8);
    SET(CNWSCreature__SetAnimation,                 0x0811B544);
    SET(CNWSCreature__SetAssociatesToForgetAggression, 0x08112c00);
    SET(CNWSCreature__SetCombatMode,                0x080F982C);
    SET(CNWSCreature__SignalMeleeDamage,            0x080EACAC);
    SET(CNWSCreature__SignalRangedDamage,           0x080E94DC);
    SET(CNWSCreature__SummonAssociate,              0x0810da28);
    SET(CNWSCreature__UnequipItem,                  0x0811B7B0);

    SET(CNWSCreatureStats__DecrementFeatRemainingUses, 0x081646EC);
    SET(CNWSCreatureStats__GetAttacksPerRound,         0x08163D18);
    SET(CNWSCreatureStats__GetBaseAttackBonus,         0x08142054);
    SET(CNWSCreatureStats__GetCanUseSkill,             0x08152e1c);
    SET(CNWSCreatureStats__GetFeatRemainingUses,       0x08153E00);
    SET(CNWSCreatureStats__GetFeatTotalUses,           0x0815479C);
    SET(CNWSCreatureStats__GetHighestLevelOfFeat,      0x0816562C);
    SET(CNWSCreatureStats__GetLevel,                   0x08163CC8);
    SET(CNWSCreatureStats__GetTotalNegativeLevels,     0x0816571C);
    SET(CNWSCreatureStats__HasFeat,                    0x08153BC4);

    SET(CNWSItem__GetMinEquipLevel,                 0x081a5de4);
    SET(CNWSItem__GetPropertyByType,                0x081A2B34);
    SET(CNWSItem__GetPropertyByTypeExists,          0x081A2A6C);
    SET(CNWSItem__GetWeight,                        0x081a6b90);

    SET(CNWMessage__CreateWriteMessage, 0x080c3aec);
    SET(CNWMessage__GetWriteMessage,    0x080c2e54);
    SET(CNWMessage__WriteBOOL,          0x080c3c08);
    SET(CNWMessage__WriteBYTE,          0x080c3c24);
    SET(CNWMessage__WriteCExoString,    0x080c2d04);
    SET(CNWMessage__WriteDWORD,         0x080c3e74);
    SET(CNWMessage__WriteWORD,          0x080c3d44);
    SET(CNWMessage__WriteINT,           0x080c3f00);

    SET(CNWSMessage__SendServerToPlayerCCMessage,   0x08078AB8);
    SET(CNWSMessage__SendServerToPlayerChatMessage, 0x0806839C);
    SET(CNWSMessage__SendServerToPlayerChat_Talk,   0x0807FE10);
    SET(CNWSMessage__SendServerToPlayerChat_Tell,   0x080694AC);
    SET(CNWSMessage__SendServerToPlayerChat_Party,  0x08068FE4);
    SET(CNWSMessage__SendServerToPlayerChat_Shout,  0x08069710);
    SET(CNWSMessage__SendServerToPlayerMessage,     0x08076f10);
    SET(CNWSMessage__WriteOBJECTIDServer,           0x08052434);

    SET(CNWSScriptVarTable__DestroyFloat,    0x081F4320);
    SET(CNWSScriptVarTable__DestroyInt,      0x081F362C);
    SET(CNWSScriptVarTable__DestroyLocation, 0x081F4458);
    SET(CNWSScriptVarTable__DestroyObject,   0x081F43F0);
    SET(CNWSScriptVarTable__DestroyString,   0x081F4388);
    SET(CNWSScriptVarTable__GetFloat,        0x081F3FF0);
    SET(CNWSScriptVarTable__GetInt,          0x081F3FC8);
    SET(CNWSScriptVarTable__GetLocation,     0x081F40E8);
    SET(CNWSScriptVarTable__GetObject,       0x081F40BC);
    SET(CNWSScriptVarTable__GetString,       0x081F4020);
    SET(CNWSScriptVarTable__SetFloat,        0x081F4190);
    SET(CNWSScriptVarTable__SetInt,          0x081F3454);
    SET(CNWSScriptVarTable__SetLocation,     0x081F4204);
    SET(CNWSScriptVarTable__SetObject,       0x081F41E0);
    SET(CNWSScriptVarTable__SetString,       0x081F41B4);

    SET(CServerExoApp__GetClientObjectByPlayerId,   0x080B24D0);
    SET(CServerExoApp__GetNWSMessage,               0x080B1F54);
    SET(CTwoDimArrays__GetEpicFortSaveBonus,        0x080B9A04);
    SET(CTwoDimArrays__GetEpicRefSaveBonus,         0x080B9A24);
    SET(CTwoDimArrays__GetEpicWillSaveBonus,        0x080B9A48);

    SET(CServerAIMaster__AddEventDeltaTime, 0x08096388);
    SET(CWorldTimer__GetCalendarDayFromSeconds, 0x08241a8c);
    SET(CWorldTimer__GetTimeOfDayFromSeconds, 0x08241af0);
}
