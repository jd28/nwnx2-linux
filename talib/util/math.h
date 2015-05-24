#ifndef _TALIB_UTIL_MATH_H_
#define _TALIB_UTIL_MATH_H_

#include <cmath>
#include <fcntl.h>
#include <unistd.h>


template <typename T> T CLAMP(T value, T low, T high) {
    return (value < low) ? low : ((value > high) ? high : value);
}

// high > low > 0
inline int true_random(int low, int high) {
    int result = -1;
    int data = open("/dev/urandom", O_RDONLY);
    unsigned int rand;
    
    read(data, &rand, sizeof(rand));
    result = (rand % (high - low + 1)) + low;
    close(data);

    return result;
}

#endif // _TALIB_UTIL_MATH_H_
