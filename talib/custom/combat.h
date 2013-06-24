#ifndef NWNX_CUSTOM_COMBAT_H
#define NWNX_CUSTOM_COMBAT_H

#include <vector>
#include "damage.h"

struct CombatWeapon {
    CombatWeapon()
        : id(OBJECT_INVALID), iter(5), ab_ability(0), dmg_ability(0),
          ab_mod(), crit_range(), crit_mult(), base_dmg_flags(),
          base_dmg_roll(), damage(), crit_dmg() {}
	  
    uint32_t                  id;

    uint16_t                  iter;
    uint16_t                  ab_ability;
    uint16_t                  dmg_ability;
    int16_t                   ab_mod;

    uint16_t                  crit_range;
    uint16_t                  crit_mult;
    bool                      has_dev_crit;
    int32_t                   power;

    uint32_t                  base_dmg_flags;
    DiceRoll                  base_dmg_roll;
    std::vector<DamageAmount> damage;
    std::vector<DamageAmount> crit_dmg;
};

struct CombatMod {
    CombatMod()
        : ab(0),
          ac(0),
          dmg(-1, DiceRoll(), false),
          hp(0) {}
    
    CombatMod(int32_t ab_, int32_t ac_, DamageAmount dmg_, int32_t hp_)
        : ab(ab_), ac(ac_), dmg(dmg_), hp(hp_) {}
    
    int32_t ab;
    int32_t ac;
    DamageAmount dmg;
    int32_t hp;
};

#endif // NWNX_CUSTOM_COMBAT_H
