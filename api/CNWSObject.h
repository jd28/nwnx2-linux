#ifndef _CNWSOBJECT_H_
#define _CNWSOBJECT_H_
#include "nwndef.h"
#include "CExoString.h"
#include "Vector.h"
#include "CResRef.h"
#include "CScriptLocation.h"
#include "nwnstructs.h"
#include "CExoLocString.h"
#include "CNWSDialog.h"
#include "CExoLinkedList.h"
#include "CNWSObjectActionNode.h"

class CNWSObject
{
public:
    unsigned long AIActionCloseDoor(CNWSObjectActionNode *);
    unsigned long AIActionDialogObject(CNWSObjectActionNode *);
    int AIActionDoCommand(CNWSObjectActionNode *);
    unsigned long AIActionGiveItem(CNWSObjectActionNode *);
    unsigned long AIActionLockObject(CNWSObjectActionNode *);
    unsigned long AIActionOpenDoor(CNWSObjectActionNode *);
    unsigned long AIActionPauseDialog(CNWSObjectActionNode *);
    unsigned long AIActionPlayAnimation(CNWSObjectActionNode *);
    unsigned long AIActionPlaySound(CNWSObjectActionNode *);
    unsigned long AIActionResumeDialog(CNWSObjectActionNode *);
    int AIActionSetCommandable(CNWSObjectActionNode *);
    int AIActionSpeakStrRef(CNWSObjectActionNode *);
    unsigned long AIActionSpeak(CNWSObjectActionNode *);
    unsigned long AIActionTakeItem(CNWSObjectActionNode *);
    unsigned long AIActionUnlockObject(CNWSObjectActionNode *);
    unsigned long AIActionUseObject(CNWSObjectActionNode *);
    int AIActionWait(CNWSObjectActionNode *);
    void AddActionAfterFront(unsigned long, unsigned short, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *);
    void AddActionNodeParameter(CNWSObjectActionNode *, unsigned long, unsigned long, void *);
    void AddActionToFront(unsigned long, unsigned short, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *);
    void AddAction(unsigned long, unsigned short, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *, unsigned long, void *);
    int AddCloseDoorAction(unsigned long, int);
    int AddDoCommandAction(void *);
    int AddEffectTarget(unsigned long);
    int AddGiveItemActions(unsigned long, unsigned long, int);
    int AddLockObjectAction(unsigned long);
    void AddLoopingVisualEffect(unsigned short, unsigned long, unsigned char);
    void AddMatchedExpressionString(CExoString const &);
    int AddOpenDoorAction(unsigned long, int);
    int AddTakeItemActions(unsigned long, unsigned long, int);
    int AddUnlockObjectAction(unsigned long, unsigned long, int);
    int AddUseObjectAction(unsigned long);
    int AnimationStationary(unsigned short);
    void ApplyEffect(CGameEffect *, int, int);
    CNWSObject * AsNWSObject();
    void BroadcastCounterSpellData(CNWSpell *, CNWCCMessageData *);
    void BroadcastDialog(CExoString, float);
    void BroadcastFloatyDataSTRREF(unsigned long);
    void BroadcastFloatyData(CNWCCMessageData *);
    void BroadcastSafeProjectile(unsigned long, unsigned long, Vector, Vector, unsigned long, unsigned char, unsigned long, unsigned char, unsigned char);
    void BroadcastSpellData(CNWSpell *, CNWCCMessageData *);
    void CalculateLastSpellProjectileTime(unsigned char);
    Vector CalculateSpellRangedMissTarget(unsigned long, unsigned long);
    int ClearAction(CNWSObjectActionNode *, int);
    void ClearAllActions();
    void ClearAllPartyInvalidActions();
    void ClearMatchedExpressionStrings();
    void ClearSpellEffectsOnOthers();
    void CopyScriptVars(CNWSScriptVarTable *);
    void DeleteCurrentAIAction();
    int DoDamageImmunity(CNWSCreature *, int, unsigned short, int, int);
    int DoDamageReduction(CNWSCreature *, int, unsigned char, int, int);
    int DoDamageResistance(CNWSCreature *, int, unsigned short, int, int, int);
    void DoDamage(int);
    int DoSpellImmunity(CNWSObject *);
    int DoSpellLevelAbsorption(CNWSObject *);
    int GetAILevel();
    int GetAILock();
    int GetAIPosList();
    unsigned char GetAIStateReaction(unsigned long);
    unsigned short GetAQActionIDByID(unsigned short, int);
    int GetAcceptableAction(unsigned long);
    int GetActionByGroupId(unsigned short, CNWSObjectActionNode **);
    int GetAnimationSpeed();
    int GetAnimation();
    int GetAppliedEffects();
    int GetApplyingPostProcessEffects();
    int GetAreaId();
    CNWSArea * GetArea();
    int GetBaseHitPoints();
    int GetConversationPlayHello();
    short GetCurrentHitPoints(int);
    int GetCustomScriptEventId();
    char GetDamageImmunityByFlags(unsigned short);
    char GetDamageImmunity(unsigned char);
    unsigned char GetDamageLevel();
    int GetDead();
    int GetDialogInterruptable();
    int GetDialogOwner();
    int GetDialogPrivate();
    CResRef GetDialogResref();
    int GetDialogValid();
    int GetEffectArrayIndex();
    unsigned long GetEffectSpellId();
    int GetEffectTargets();
    int GetExecutingAIAction();
    int GetExpressionStrings();
    CExoLocString & GetFirstName();
    unsigned char GetGender();
    int GetHasFeatEffectApplied(unsigned short);
    unsigned short GetIDByAQActionID(unsigned short);
    int GetInventoryDisturbItem();
    int GetInventoryDisturbType();
    int GetIsDestroyable();
    int GetIsPCDying();
    int GetIsRaiseable();
    int GetKiller();
    int GetLastAttackMode();
    int GetLastAttackType();
    int GetLastAttacker();
    CExoString GetLastConversationResref();
    int GetLastDamageAmountByFlags(int);
    int GetLastDamager();
    int GetLastDisturbed();
    int GetLastGroupID();
    int GetLastHostileActor();
    CExoLocString & GetLastName();
    int GetLastSpeaker();
    int GetLastSpellCastAtMeCaster();
    int GetLastSpellCastAtMeHarmful();
    int GetLastSpellCastAtMe();
    int GetLastSpellCastDomainLevel();
    int GetLastSpellCastFeat();
    int GetLastSpellCastMetaType();
    int GetLastSpellCastMulticlass();
    int GetLastSpellCastSpontaneous();
    int GetLastSpellCast();
    int GetLastSpellId();
    int GetLastSpellLocationTarget();
    int GetLastSpellObjectTarget();
    int GetLastWeaponAttackedWith();
    CNWSExpression * GetListenExpressionObj(int);
    int GetListenExpressions();
    unsigned long GetLockOrientationToObject();
    int GetLoopingVisualEffects();
    int GetMatchedPos();
    short GetMaxHitPoints(int);
    int GetMaximumDamageResistanceVsDamageFlag(unsigned short, int *);
    unsigned long GetNearestObjectByName(CExoString const &, float);
    int GetNewGroupID();
    int GetNodeById(unsigned short, unsigned short);
    int GetNumActionGroups();
    int GetObjectToDialog();
    int GetOpenDoorAnimationPlayed();
    int GetOrientation();
    int GetPendingEffectRemoval();
    int GetPlotObject();
    unsigned short GetPortraitId();
    CResRef GetPortrait();
    CExoLinkedListNode * GetPositionByGroupIndex(int);
    int GetPosition();
    int GetPrivateConversation();
    int GetQueuedActionsList();
    int GetReputation(unsigned long, int &, int);
    int GetSavingThrowSpellId();
    CScriptLocation GetScriptLocation();
    int GetScriptVarTable();
    int GetSelectableWhenDead();
    CExoString * GetTag();
    CExoString * GetTemplate();
    int GetTemporaryHitPoints();
    int HasSpellEffectApplied(unsigned long);
    int IsAbleToModifyActionQueue();
    int IsDialogDelay();
    int IsDialogPaused();
    int IsListening();
    int IsPCInDialog();
    void LoadActionQueue(CResGFF *, CResStruct *);
    void LoadEffectList(CResGFF *, CResStruct *);
    void LoadListenData(CResGFF *, CResStruct *);
    void LoadObjectState(CResGFF *, CResStruct *);
    void LoadVarTable(CResGFF *, CResStruct *);
    void PlaySoundSet(CNWSPlayer *, unsigned char);
    void RemoveEffectByCreator(unsigned long);
    int RemoveEffectById(unsigned long long);
    int RemoveEffectBySpellId(unsigned long);
    void RemoveEffectTarget(unsigned long);
    void RemoveEffect(CGameEffect *);
    void RemoveGroup(unsigned short);
    void RemoveLoopingVisualEffect(unsigned short);
    int RemoveObjectFromDialog(unsigned long);
    void RemoveSomeEffectsOfDurationType(unsigned short);
    int ReplyDialog(unsigned long, unsigned long, int, unsigned long);
    void ReportOverflow(int, int, int, int);
    int RunActions(unsigned long, unsigned long, unsigned long long);
    int RunDialogOneLiner(CExoString const &, unsigned long);
    void SaveActionQueue(CResGFF *, CResStruct *);
    void SaveEffectList(CResGFF *, CResStruct *);
    void SaveListenData(CResGFF *, CResStruct *);
    void SaveObjectState(CResGFF *, CResStruct *);
    void SaveVarTable(CResGFF *, CResStruct *);
    int SendDialogEntry(unsigned long, int);
    int SendDialogReplies();
    int SetAILevel(int);
    int SetAILock(int);
    int SetAIPosList(CExoLinkedListNode *);
    int SetAbleToModifyActionQueue(int);
    int SetAnimationSpeed(float);
    void SetAnimation(int);
    int SetApplyingPostProcessEffects(int);
    int SetAreaId(unsigned long);
    void SetArea(CNWSArea *);
    int SetBaseHitPoints(int);
    int SetConversationPlayHello(int);
    int SetCurrentActionTarget(unsigned long);
    int SetCurrentHitPoints(int);
    int SetCustomScriptEventId(int);
    void SetDamageImmunity(unsigned short, int);
    int SetDialogAnimation(int);
    void SetDialogDelay(float);
    void SetDialogOwner(unsigned long);
    int SetDialogPaused(int);
    int SetEffectArrayIndex(unsigned short);
    void SetEffectSpellId(unsigned long);
    int SetExecutingAIAction(CNWSObjectActionNode *);
    void SetGroupInterruptable(unsigned short, int);
    int SetInventoryDisturbItem(unsigned long);
    int SetInventoryDisturbType(int);
    int SetIsDestroyable(int);
    int SetIsRaiseable(int);
    int SetKiller(unsigned long);
    int SetLastAnimationTimes(unsigned long, unsigned long);
    int SetLastAttackMode(unsigned char);
    int SetLastAttackType(unsigned short);
    int SetLastAttacker(unsigned long);
    void SetLastConversationResref(CExoString);
    int SetLastDamageAmount(int, int);
    int SetLastDamager(unsigned long);
    int SetLastDisturbed(unsigned long);
    int SetLastGroupID(unsigned short);
    void SetLastHostileActor(unsigned long, int);
    int SetLastSpeaker(unsigned long);
    int SetLastSpellCastAtMeCaster(unsigned long);
    int SetLastSpellCastAtMeHarmful(int);
    int SetLastSpellCastAtMe(unsigned long);
    int SetLastSpellCastDomainLevel(unsigned char);
    int SetLastSpellCastFeat(unsigned short);
    int SetLastSpellCastMetaType(unsigned char);
    int SetLastSpellCastMulticlass(unsigned char);
    int SetLastSpellCastSpontaneous(int);
    int SetLastSpellCast(int);
    int SetLastSpellId(unsigned long);
    int SetLastSpellLocationTarget(Vector);
    int SetLastSpellObjectTarget(unsigned long);
    int SetLastWeaponAttackedWith(unsigned long);
    int SetListenExpression(CExoString, int);
    int SetListening(int);
    void SetLockOrientationToObject(unsigned long);
    int SetMatchedPos(int);
    int SetOpenDoorAnimationPlayed(int);
    void SetOrientation(Vector);
    int SetPendingEffectRemoval(int);
    int SetPlotObject(int);
    void SetPortraitId(unsigned short);
    void SetPortrait(CResRef);
    void SetPosition(Vector, int);
    int SetPrivateConversation(int);
    int SetSavingThrowSpellId(unsigned long);
    int SetSelectableWhenDead(int);
    int SetStartActionTimer(unsigned long, unsigned long);
    void SetTag(CExoString);
    int SetTemplate(CExoString const &);
    int SetTemporaryHitPoints(int);
    void SpawnBodyBag();
    void SpellCastAndImpact(unsigned long, Vector, unsigned long, unsigned char, unsigned long, int, int, unsigned char, int);
    int StartDialog(unsigned long, CExoString const &, int, int);
    int StopDialog();
    int TerminateAISliceAfterAction(unsigned long);
    int TestActionList();
    int TestListenExpression(CExoString);
    void UpdateAttributesOnEffect(CGameEffect *, int);
    int UpdateDialog();
    void UpdateEffectList(unsigned long, unsigned long);
    void UpdateEffectPtrs();
    ~CNWSObject();
    CNWSObject(unsigned char, unsigned long, int, int);

    /* 0x0/0 */ unsigned long field_0;
    /* 0x4/4 */ unsigned long ObjectID;
    /* 0x8/8 */ char ObjectType;
    /* 0x9/9 */ char field_9;
    /* 0xA/10 */ char field_A;
    /* 0xB/11 */ char field_B;
    /* 0xC/12 */ CNWSObjectMethods *Methods;
    /* 0x10/16 */ CExoLocString LocString;
    /* 0x18/24 */ char rsvd1[4];
    /* 0x18/24 */ unsigned short field_18;
    /* 0x1A/26 */ unsigned short field_1A;
    /* 0x1C/28 */ CExoString Tag;
    /* 0x24/36 */ CExoString ResRef;
    /* 0x2C/44 */ CResRef field_2C;
    /* 0x40/64 */ char rsvd2[4];
    /* 0x40/64 */ CNWSDialog *Dialog;
    /* 0x44/68 */ unsigned long field_44;
    /* 0x48/72 */ unsigned long field_48;
    /* 0x4C/76 */ unsigned long field_4C;
    /* 0x50/80 */ unsigned long field_50;
    /* 0x54/84 */ unsigned long field_54;
    /* 0x58/88 */ unsigned long ConversationWith;
    /* 0x5C/92 */ unsigned long InConversation;
    /* 0x60/96 */ unsigned long AILevel;
    /* 0x64/100 */ unsigned long field_64;
    /* 0x68/104 */ unsigned long field_68;
    /* 0x6C/108 */ unsigned long field_6C;
    /* 0x70/112 */ unsigned long ActionTarget;
    /* 0x78/120 */ char rsvd3[4];
    /* 0x78/120 */ unsigned long AreaID;
    /* 0x7C/124 */ Vector m_vPosition;
    /* 0x88/136 */ Vector m_vOrientation;
    /* 0xB8/184 */ char rsvd4[36];
    /* 0xB8/184 */ unsigned long HitPoints;
    /* 0xBC/188 */ unsigned short field_BC;
    /* 0xBE/190 */ char field_BE;
    /* 0xC0/192 */ char rsvd5;
    /* 0xC0/192 */ unsigned short TempHitPoints;
    /* 0xC2/194 */ unsigned short field_C2;
    /* 0xC4/196 */ unsigned long CanModifyActionQueue;
    /* 0xC8/200 */ unsigned long IsDestroyable;
    /* 0xCC/204 */ unsigned long IsRaiseable;
    /* 0xD0/208 */ unsigned long DeadSelectable;
    /* 0xD4/212 */ unsigned long Invulnerable;
    /* (mtype:CExoLinkedList<CNWSObjectActionNode>) */
    /* 0xD8/216 */ CExoLinkedList<CNWSObjectActionNode> ActionsList;
    /* 0xDC/220 */ unsigned long ScriptVarTable;
    /* 0xE0/224 */ unsigned long field_E0;
    /* 0xE4/228 */ unsigned long field_E4;
    /* 0xE8/232 */ unsigned long field_E8;
    /* 0xEC/236 */ void *Effects;
    /* 0xF8/248 */ char rsvd6[8];
    /* 0xF8/248 */ unsigned long PerceptionList;
    /* 0x1C0/448 */ char rsvd7[196];
    /* 0x1C0/448 */ unsigned long field_1C0;
};
#endif
