#ifndef TALIB_CUSTOM_DAMAGE_H
#define TALIB_CUSTOM_DAMAGE_H

#include <utility>
#include <vector>
#include <ostream>
#include "dice.h"

// NOTE: This assumes that there is only one bit set in the damage flag.
// getting the index with multiple bits set will return index of the first
// bit.
static inline int32_t GetDamageIndexFromFlag(uint32_t flag) {
    return __builtin_ffs(flag) - 1;
}

static inline uint32_t GetDamageFlagFromIPConst(uint32_t type) {
    switch(type) {
    default: return -1;
    case IP_CONST_DAMAGETYPE_BLUDGEONING: return DAMAGE_TYPE_BLUDGEONING;
    case IP_CONST_DAMAGETYPE_PIERCING: return DAMAGE_TYPE_PIERCING;
    case IP_CONST_DAMAGETYPE_SLASHING: return DAMAGE_TYPE_SLASHING;
    case IP_CONST_DAMAGETYPE_MAGICAL: return DAMAGE_TYPE_MAGICAL;
    case IP_CONST_DAMAGETYPE_ACID: return DAMAGE_TYPE_ACID;
    case IP_CONST_DAMAGETYPE_COLD: return DAMAGE_TYPE_COLD;
    case IP_CONST_DAMAGETYPE_DIVINE: return DAMAGE_TYPE_DIVINE;
    case IP_CONST_DAMAGETYPE_ELECTRICAL: return DAMAGE_TYPE_ELECTRICAL;
    case IP_CONST_DAMAGETYPE_FIRE: return DAMAGE_TYPE_FIRE;
    case IP_CONST_DAMAGETYPE_NEGATIVE: return DAMAGE_TYPE_NEGATIVE;
    case IP_CONST_DAMAGETYPE_POSITIVE: return DAMAGE_TYPE_POSITIVE;
    case IP_CONST_DAMAGETYPE_SONIC: return DAMAGE_TYPE_SONIC;
    }
}

static inline uint32_t GetDamageIndexFromIPConst(uint32_t type) {
    switch(type) {
    default: return -1;
    case IP_CONST_DAMAGETYPE_BLUDGEONING: return DAMAGE_INDEX_BLUDGEONING;
    case IP_CONST_DAMAGETYPE_PIERCING: return DAMAGE_INDEX_PIERCING;
    case IP_CONST_DAMAGETYPE_SLASHING: return DAMAGE_INDEX_SLASHING;
    case IP_CONST_DAMAGETYPE_MAGICAL: return DAMAGE_INDEX_MAGICAL;
    case IP_CONST_DAMAGETYPE_ACID: return DAMAGE_INDEX_ACID;
    case IP_CONST_DAMAGETYPE_COLD: return DAMAGE_INDEX_COLD;
    case IP_CONST_DAMAGETYPE_DIVINE: return DAMAGE_INDEX_DIVINE;
    case IP_CONST_DAMAGETYPE_ELECTRICAL: return DAMAGE_INDEX_ELECTRICAL;
    case IP_CONST_DAMAGETYPE_FIRE: return DAMAGE_INDEX_FIRE;
    case IP_CONST_DAMAGETYPE_NEGATIVE: return DAMAGE_INDEX_NEGATIVE;
    case IP_CONST_DAMAGETYPE_POSITIVE: return DAMAGE_INDEX_POSITIVE;
    case IP_CONST_DAMAGETYPE_SONIC: return DAMAGE_INDEX_SONIC;
    }
}

static inline std::string DamageIndexToString(int32_t idx) {
    switch(idx) {
    default: return "Unknown";
    case DAMAGE_INDEX_BLUDGEONING: return "Bludgeoning";
    case DAMAGE_INDEX_PIERCING:    return "Piercing";
    case DAMAGE_INDEX_SLASHING:    return "Slashing";
    case DAMAGE_INDEX_MAGICAL:     return "Magical";
    case DAMAGE_INDEX_ACID:        return "Acid";
    case DAMAGE_INDEX_COLD:        return "Cold";
    case DAMAGE_INDEX_DIVINE:      return "Divine";
    case DAMAGE_INDEX_ELECTRICAL:  return "Electrical";
    case DAMAGE_INDEX_FIRE:        return "Fire";
    case DAMAGE_INDEX_NEGATIVE:    return "Negative";
    case DAMAGE_INDEX_POSITIVE:    return "Positive";
    case DAMAGE_INDEX_SONIC:       return "Sonic";
    case DAMAGE_INDEX_BASE_WEAPON: return "Physical";
    }
}


// NOTE: The first element of the pair MUST be the damage
// index, not the damage flag!
struct DamageAmount {
    DamageAmount()
        : type(-1), 
          roll(), 
          penalty(false) {}
    DamageAmount(int32_t t, DiceRoll d, bool p)
        : type(t),
          roll(d), 
          penalty(false) {}

    bool operator==(const DamageAmount& other) const {
        return ( type    == other.type &&
                 roll    == other.roll &&
                 penalty == other.penalty );
    }
    bool operator!=(const DamageAmount& other) const {
        return !(*this == other);
    }

    int32_t  type;
    DiceRoll roll;
    bool     penalty;
};

static inline std::ostream &operator<<(std::ostream &out, const DamageAmount &o) {
    out << o.roll << " of " << DamageIndexToString(o.type);
    return out;
}

#endif // TALIB_CUSTOM_DAMAGE_H
