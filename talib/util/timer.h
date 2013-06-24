#ifndef TALIB_UTIL_TIMER_H
#define TALIB_UTIL_TIMER_H

inline uint64_t ClockGetTime(){
    timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (uint64_t)ts.tv_sec * 1000000LL + (uint64_t)ts.tv_nsec / 1000LL;
}

#endif // TALIB_UTIL_TIMER_H
