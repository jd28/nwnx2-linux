#ifndef NWNX_SOLSTICE_OBJECT_CREATURE_H
#define NWNX_SOLSTICE_OBJECT_CREATURE_H

#include "NWNXLib.h"
#include "talib/nwn/all.h"

struct DamageRoll {
    DamageRoll() : type(0), roll(), mask(0) {}

    int32_t  type;
    DiceRoll roll;
    int32_t  mask;
};

struct CombatMod {
    CombatMod() : ab(0), ac(0), dmg() , hp(0) {}

    int32_t ab;
    int32_t ac;
    DamageRoll dmg;
    int32_t hp;
};

struct DamageResult {
    int32_t    damages[DAMAGE_INDEX_NUM];
    int32_t    damages_unblocked[DAMAGE_INDEX_NUM];
    int32_t    immunity[DAMAGE_INDEX_NUM];
    int32_t    resist[DAMAGE_INDEX_NUM];
    int32_t    resist_remaining[DAMAGE_INDEX_NUM];
    int32_t    reduction, reduction_remaining, parry;

    void add(const DamageRoll dmg, int32_t mult) {
        if ( rollIsValid(dmg.roll) ) {
            // Critical damage is applied once, not multiplied.
            if ( mult > 1 && (dmg.mask & 2) ) {
                mult = 1;
            }

            int32_t roll = rollDice(dmg.roll, mult);

            if ( dmg.mask & 1 ) { roll = -roll; }

            if ( dmg.mask & 4 ) {
                damages_unblocked[dmg.type] += roll;
            }
            else {
                damages[dmg.type] += roll;
            }
        }
    }
    void compactPhysicals() {
        damages[12] += damages[0] + damages[1] + damages[2];
        damages[0] = damages[1] = damages[2] = 0;

        damages_unblocked[12] += damages_unblocked[0] +
            damages_unblocked[1] + damages_unblocked[2];
        damages_unblocked[0] = damages_unblocked[1] = damages_unblocked[2] = 0;
    }

    void finalize() {
        for ( int i = 0; i < DAMAGE_INDEX_NUM; ++i ) {
            damages[i] += damages_unblocked[i];
        }
    }
    int32_t getTotal() const {
        int32_t res = 0;
        for ( int i = 0; i < DAMAGE_INDEX_NUM; ++i ) {
            res += damages[i];
        }
        return res;
    }
};

struct Offense {
    int32_t       ab_base;
    int32_t       ab_transient;
    int32_t       attacks_on;
    int32_t       attacks_off;
    int32_t       offhand_penalty_on;
    int32_t       offhand_penalty_off;
    int32_t       ranged_type;
    int32_t       weapon_type;
    DamageRoll    damage[20];
    int32_t       damage_len;
};

struct Defense {
    int32_t       concealment;
    int32_t       hp_eff;
    int32_t       hp_max;

    int32_t       soak;
    int32_t       soak_stack[DAMAGE_POWER_NUM];

    int32_t       immunity[DAMAGE_INDEX_NUM];
    int32_t       immunity_base[DAMAGE_INDEX_NUM];

    int32_t       immunity_misc[IMMUNITY_TYPE_NUM];

    int32_t       resist[DAMAGE_INDEX_NUM];
    int32_t       resist_stack[DAMAGE_INDEX_NUM];

    /*Saves         saves;*/
};

struct CombatWeapon {
    uint32_t                  id;

    int32_t                   iter;
    int32_t                   ab_ability;
    int32_t                   dmg_ability;
    int32_t                   ab_mod;
    int32_t                   transient_ab_mod;

    int32_t                   crit_range;
    int32_t                   crit_mult;
    int32_t                   power;

    uint32_t                  base_dmg_flags;
    DiceRoll                  base_dmg_roll;

    DamageRoll                damage[50];
    int32_t                   damage_len;
    bool                      has_dev_crit;
};


struct CombatInfo {
    Offense         offense;
    Defense         defense;
    CombatWeapon    equips[EQUIP_TYPE_NUM];
    CombatMod       mods[COMBAT_MOD_NUM];
    CombatMod       mod_situ[SITUATION_NUM];
    CombatMod       mod_mode;
    int32_t         effective_level;
    int32_t         first_custom_eff;
    uint32_t        fe_mask;
    uint32_t        training_vs_mask;
    int32_t         skill_eff[SKILL_NUM];
    int32_t         ability_eff[ABILITY_NUM];
    int32_t         update_flags;
};

class Creature {
public:
    CNWSCreature *original;
    CombatInfo    info;

    Creature (CNWSCreature *cre)
        : original(cre)
        , info() {

        memset(&info, 0, sizeof(CombatInfo));
    }

    ~Creature() = default;

    void update();
};

#endif // NWNX_SOLSTICE_OBJECT_CREATURE_H
