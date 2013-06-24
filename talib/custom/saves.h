#ifndef TALIB_CUSTOM_SAVES_H
#define TALIB_CUSTOM_SAVES_H

#include <array>
#include <algorithm>

struct Save {
    Save() 
        : base(0) {
        std::fill_n(effects, 20, 0);
    }

    int32_t base;
    int16_t effects[20];
};

struct Saves {
    Saves() 
        : reflex(),
          fort(),
          will() {}

    Save reflex;
    Save fort;
    Save will;
};

#endif // TALIB_CUSTOM_SAVES_H
