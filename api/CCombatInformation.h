#ifndef _CCOMBATINFORMATION_H_
#define _CCOMBATINFORMATION_H_
#include "nwndef.h"
#include "CExoArrayList.h"
#include "CExoString.h"

class CCombatInformation
{
public:
    int LoadData(CResGFF *, CResStruct *);
    int SaveData(CResGFF *, CResStruct *);
    ~CCombatInformation();
    CCombatInformation();
    CCombatInformation & operator=(CCombatInformation &);
    int operator==(CCombatInformation &);
    int operator!=(CCombatInformation &);

    uint8_t NumAttacks;
    uint8_t OnhandAttackMod;
    uint8_t OnhandDamageMod;
    uint8_t OffhandAttackMod;
    uint8_t OffhandDamageMod;
    uint8_t Spell_resistance;
    uint8_t ArcaneSpellFailure;
    uint8_t ArmorCheckPenalty;
    uint8_t UnarmedDamageDice;
    uint8_t UnarmedDamageDie;
    uint8_t field_0A;  // Creature attack dice...
    uint8_t field_0B;
    uint8_t field_0C;
    uint8_t field_0D;
    uint8_t field_0E;
    uint8_t field_0F;
    uint8_t field_10;
    uint8_t field_11;
    uint8_t field_12;
    uint8_t OnhandCritRange;
    uint8_t OnhandCritMult;
    uint8_t field_15;
    uint8_t field_16;
    uint8_t field_17;
    uint8_t IsOffhandWeaponEquipped;
    uint8_t field_19;
    uint8_t field_1A;
    uint8_t field_1B;
    uint8_t OffhandCritRange;
    uint8_t OffhandCritMult;
    uint8_t field_1E;
    uint8_t field_1F;
    CExoArrayList<CCombatInformationNode*> AttackMods;
    CExoArrayList<CCombatInformationNode*> DamageMods;
    uint32_t RighthandObject;
    uint32_t LefthandObject;
    CExoString RightString;
    CExoString LeftString;
    uint8_t DamageDice;
    uint8_t DamageDie;
    uint8_t field_52;
    uint8_t field_53;
};

static_assert(sizeof(CCombatInformation) == 0x54, "CCombatInformation has an incorrect size.");
#endif
