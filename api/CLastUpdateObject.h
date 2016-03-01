#ifndef _CLASTUPDATEOBJECT_H_
#define _CLASTUPDATEOBJECT_H_
#include "nwndef.h"
#include "nwnstructs.h"

class CLastUpdateObject
{
public:
    void InitializeQuickbar();
    ~CLastUpdateObject();
    CLastUpdateObject();

    /* 0x0000/0000 */ CNWSCreatureAppearanceInfo CreatureAppearanceInfo;
    /* 0x0040/0064 */ unsigned long field_0040;
    /* 0x0044/0068 */ unsigned short field_0044;
    /* 0x0046/0070 */ unsigned short SoundSetFile;
    /* 0x0048/0072 */ unsigned long FootstepType;
    /* 0x004C/0076 */ nwobjid ObjectID;
    /* 0x0050/0080 */ Vector Position;
    /* 0x005C/0092 */ nwobjid Area;
    /* 0x0060/0096 */ Vector Orientation;
    /* 0x006C/0108 */ unsigned long field_006C;
    /* 0x0070/0112 */ unsigned long field_0070;
    /* 0x0074/0116 */ unsigned long field_0074;
    /* 0x0078/0120 */ unsigned long field_0078;
    /* 0x007C/0124 */ unsigned long field_007C;
    /* 0x0080/0128 */ unsigned short field_0080;
    /* 0x0082/0130 */ unsigned short field_0082;
    /* 0x0084/0132 */ unsigned char AIState;
    /* 0x0085/0133 */ unsigned char field_0085;
    /* 0x0086/0134 */ unsigned short field_0086;
    /* 0x0088/0136 */ unsigned long InCombat;
    /* 0x008C/0140 */ unsigned long field_008C;
    /* 0x0090/0144 */ unsigned long LockOrientationToObject;
    /* 0x0094/0148 */ unsigned long field_0094;
    /* 0x0098/0152 */ CResRef Portrait;
    /* 0x00A8/0168 */ unsigned long field_00A8;
    /* 0x00AC/0172 */ CExoLocString field_00AC;
    /* 0x00B4/0180 */ CExoLocString field_00B4;
    /* 0x00BC/0188 */ float WalkRate;
    /* 0x00C0/0192 */ float RunRate;
    /* 0x00C4/0196 */ CExoArrayList<CLoopingVisualEffect *> VisualEffectList;
    /* 0x00D0/0208 */ unsigned long field_00D0;
    /* 0x00D4/0212 */ unsigned short field_00D4;
    /* 0x00D6/0214 */ unsigned short CurrentHitPoints;
    /* 0x00D8/0216 */ unsigned short field_00D8;
    /* 0x00DA/0218 */ unsigned short TempHitPoints;
    /* 0x00DC/0220 */ unsigned short MaxHitPoints;
    /* 0x00DE/0222 */ unsigned short field_00DE;
    /* 0x00E0/0224 */ unsigned long field_00E0;
    /* 0x00E4/0228 */ unsigned long IsPartyLeader;
    /* 0x00E8/0232 */ unsigned long field_00E8;
    /* 0x00EC/0236 */ unsigned long field_00EC;
    /* 0x00F0/0240 */ CExoArrayList<unsigned long> field_00F0;
    /* 0x00FC/0252 */ unsigned long Trapped;
    /* 0x0100/0256 */ unsigned long TrapFlagged;
    /* 0x0104/0260 */ unsigned long TrapFaction;
    /* 0x0108/0264 */ unsigned long Locked;
    /* 0x010C/0268 */ unsigned long Lockable;
    /* 0x0110/0272 */ unsigned long TrapRecoverable;
    /* 0x0114/0276 */ unsigned char AIStateReaction;
    /* 0x0115/0277 */ unsigned char field_0115;
    /* 0x0116/0278 */ unsigned char field_0116;
    /* 0x0117/0279 */ unsigned char field_0117;
    /* 0x0118/0280 */ nwobjid MasterID;
    /* 0x011C/0284 */ unsigned long field_011C;
    /* 0x0120/0288 */ unsigned long field_0120;
    /* 0x0124/0292 */ unsigned long field_0124;
    /* 0x0128/0296 */ unsigned short field_128;
    /* 0x012A/0298 */ unsigned short field_012A;
    /* 0x012C/0300 */ unsigned long field_012C;
    /* 0x0130/0304 */ unsigned long field_0130;
    /* 0x0134/0308 */ unsigned short Race;
    /* 0x0136/0310 */ unsigned short field_0136;
    /* 0x0138/0312 */ CExoString Subrace;
    /* 0x0140/0320 */ CExoString Deity;
    /* 0x0148/0328 */ unsigned long field_0148;
    /* 0x014C/0332 */ unsigned long field_014C;
    /* 0x0150/0336 */ unsigned long IsPC;
    /* 0x0154/0340 */ unsigned long DeadSelectable;
    /* 0x0158/0344 */ unsigned long Lootable;
    /* 0x015C/0348 */ unsigned long field_015C;
    /* 0x0160/0352 */ unsigned long field_0160;
    /* 0x0164/0356 */ unsigned long field_0164;
    /* 0x0168/0360 */ unsigned long field_0168;
    /* 0x016C/0364 */ unsigned long field_016C;

};

static_assert_size(CLastUpdateObject, 0x170);

#endif
