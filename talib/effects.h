#include "NWNXLib.h"
#include "custom/armor_class.h"

//extern C {

ArmorClass GetArmorClassEffects(CNWSCreature *cre, VersuInfo vs,
                                bool penalty, bool item_stack,
                                bool spell_stack);

int32_t GetAbilityEffects(CNWSCreature *cre, int32_t type, int32_t ability,
                          bool item_stack, bool spell_stack)

int32_t GetAttackEffects(CNWSCreature *cre, VersuInfo vs,
                         bool penalty, bool item_stack, bool spell_stack);

int32_t GetImmunityEffects(CNWSCreature *cre, VersusInfo vs, int32_t immunity,
                           bool item_stack, bool spell_stack);

int32_t GetSaveEffects(CNWSCreature *cre, VersusInfo vs, int32_t type,
                       int32_t save, int32_t save_vs, bool item_stack,
                       bool spell_stack);

int32_t GetSkillEffect(CNWSCreature *cre, VersusInfo vs, int32_t type, uint8_t skill,
                       bool item_stack, bool spell_stack);

}
