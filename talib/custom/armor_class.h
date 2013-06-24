#ifndef TALIB_CUSTOM_ARMOR_CLASS_H
#define TALIB_CUSTOM_ARMOR_CLASS_H

#include <utility>

typedef std::pair<int32_t, int32_t> ArmorAmount;

struct ArmorClass {
    int32_t armor;
    int32_t deflection;
    int32_t dodge;
    int32_t natural;
    int32_t shield;
};

#endif // TALIB_CUSTOM_ARMOR_CLASS_H
