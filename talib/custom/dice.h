#ifndef TALIB_CUSTOM_DICE_H
#define TALIB_CUSTOM_DICE_H

#include <ostream>
#include <stdlib.h>

struct DiceRoll {
    DiceRoll ()
    	: dice(), sides(), bonus() {}
    DiceRoll (uint16_t d, uint16_t s, uint32_t b)
        : dice(d), sides(s), bonus(b) {}
    
    uint32_t roll(uint32_t n = 1) const {
        if ( n <= 0 ) { n = 1; }
        uint32_t r = 0;
        for ( int i = dice * n; i > 0; --i ) {
            r += (rand() % sides + 1);
        }
        return r + bonus;
    }

    bool isValid() {
        return (dice > 0 && sides > 0) || bonus > 0;
    }

    bool operator==(const DiceRoll& other) const {
        return ( dice  == other.dice  &&
                 sides == other.sides &&
                 bonus == other.bonus );
    }
    bool operator!=(const DiceRoll& other) const {
        return !(*this == other);
    }
    
    uint16_t dice;
    uint16_t sides;
    uint32_t bonus;
};

static inline std::ostream &operator<<(std::ostream &out, const DiceRoll &o) {
    out << o.dice << "d" << o.sides << " + " << o.bonus;
    return out;
}

#endif // TALIB_CUSTOM_DICE_H
