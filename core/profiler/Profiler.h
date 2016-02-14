#pragma once
#include <vector>
#include <future>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <iosfwd>
#include <iterator>
#include <chrono>
#pragma GCC push_options
#pragma GCC optimize ("-O3")

namespace Profiler
{
class Profiler;
}

extern std::unique_ptr<Profiler::Profiler> profiler;

namespace Profiler
{

using clock = std::chrono::steady_clock;
using time_point = std::chrono::steady_clock::time_point;
using NS = std::chrono::nanoseconds;
using US = std::chrono::microseconds;
using MS = std::chrono::milliseconds;

template <class Rep, class Period>
constexpr int64_t to_ns(const std::chrono::duration<Rep, Period>& d)
{
    return std::chrono::duration_cast<NS>(d).count();
}

template <class Rep, class Period>
constexpr int64_t to_us(const std::chrono::duration<Rep, Period>& d)
{
    return std::chrono::duration_cast<US>(d).count();
}

template <class Rep, class Period>
constexpr int64_t to_ms(const std::chrono::duration<Rep, Period>& d)
{
    return std::chrono::duration_cast<MS>(d).count();
}

struct MetricVariant {
    enum class Types
    {
        NONE,
        INT,
        STRING,
        STRING_SHORT, // Optimization for resref and short string parameters.
        DOUBLE,
    };

    Types type;
    union {
        int64_t a_int;
        char* a_string;
        double a_double;
        char a_string_short[16];
    };

    MetricVariant() : type(Types::NONE) {}
    MetricVariant(MetricVariant&& other);
    MetricVariant& operator=(MetricVariant&& other);
    MetricVariant(const MetricVariant& other) = delete;
    MetricVariant& operator=(const MetricVariant& other) = delete;

#ifdef NWNX_PROFILER_ENABLED
    MetricVariant(int64_t val)
        : type(Types::INT), a_int(val) {}
    // Next two are needed for ambiguity with const char*
    MetricVariant(int32_t val)
        : type(Types::INT), a_int(val) {}
    MetricVariant(uint32_t val)
        : type(Types::INT), a_int(val) {}
    MetricVariant(const std::string& val)
        : MetricVariant(val.c_str()) {}
    MetricVariant(double val)
        : type(Types::DOUBLE), a_double(val) {}
    MetricVariant(const char* val) {
        int len = strlen(val);
        if (strlen(val) <= 16) {
            memcpy(a_string_short, val, len);
            if (len < 16) {
                a_string_short[len] = 0;
            }
            type = Types::STRING_SHORT;
        } else {
            type = Types::STRING;
            a_string = val ? strdup(val) : nullptr;
        }
    }

    ~MetricVariant() {
        if (type == Types::STRING && a_string) {
            free(a_string);
        }
        type = Types::NONE;
    }
#else
    // Make sure we don't allocate anything if the profiler is disabled.
    template <typename T>
    MetricVariant(T whatever) : type(Types::NONE) {}
#endif
};

std::ostream& operator<<(std::ostream& out, const MetricVariant& arg);

struct Metric {
    const char* name = nullptr;
    MetricVariant value;
    bool is_tag = false;

    Metric() = default;
    Metric(const char* name, MetricVariant value, bool tag = false)
        : name {name}, value {std::move(value)}, is_tag {tag}
    {}
};

struct Event {
    const char* category = nullptr;
    const char* name = nullptr;
    std::vector<Metric> args;
    time_point ts_start;
    time_point ts_end;

    Event() = default;
    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;
    Event(Event&&) = default;
    Event& operator=(Event&&) = default;
};

// Interface for the profiler sinks.
class Sink
{
public:
    virtual void flush(const std::vector<Event>& events, time_point base_line) = 0;
    virtual ~Sink() {}
};

class Timer;

class Profiler
{
    std::vector<Event> event_buffer[2];
    std::vector<std::unique_ptr<Sink>> sinks;
    std::atomic<bool> is_flushing;
    std::future<void> result;
    int current_buffer = 0;
    MS flush_freq = MS(5000);
    uint32_t flush_size = 0;
    time_point last_flush;
    time_point base_line;
    bool is_profiling = false;
    int depth = 0;

public:
    Event& operator[](int index) {
        return event_buffer[current_buffer][index];
    }

    void Flush(time_point now) {
        if (is_flushing || event_buffer[current_buffer].size() == 0) {
            return;
        }
        is_flushing = true;
        last_flush = now;
        int oldbuf = current_buffer;
        current_buffer = (current_buffer + 1) % 2;
        result = std::async(std::launch::async, [this, oldbuf] {
            for (auto& sink : sinks) {
                sink->flush(event_buffer[oldbuf], base_line);
            }
            event_buffer[oldbuf].clear();
            is_flushing = false;
        });
    }

public:
    Profiler()
        : is_flushing {false} {
        printf("* PROFILER: clock steady: %s, period::den: %lld\n",
        clock::is_steady ? "Yep!" : "Nah.",
        clock::period::den);

        if (!clock::is_steady) {
            printf("* PROFILER: Timer we want to use isn't steady; cannot be used "
                   " for profiling!\n");
            //exit(1);
        }

        if (clock::period::den < 1000000000LL) {
            printf("* PROFILER: Timer we want to use hasn't enough precision "
                   "for profiling. Expected: %lld, got: %lld\n!", 1000000000LL,
                   clock::period::den);
            printf("* PROFILER: Your data will be very inaccurate!\n");
        }

        base_line = last_flush = clock::now();
        // The profiler double buffers events.  Writing to one will the other is
        // flushed on a seperate thread.
        event_buffer[0].reserve(10000);
        event_buffer[1].reserve(10000);
    }
    ~Profiler() {
        ForceFlush();
    }

    int AcquireEventIndex() {
        if (!is_profiling || sinks.size() == 0) {
            return -1;
        }
        // As you can see the event vector size limit and event collection time limit
        // aren't necessarily strictly enforced.
        time_point now = clock::now();
        if (depth == 0) {
            if (!is_flushing && now - last_flush > flush_freq) {
                Flush(now);
            }
        }
        ++depth;
        event_buffer[current_buffer].emplace_back();
        return event_buffer[current_buffer].size() - 1;
    }

    void ReleaseEventIndex() {
        --depth;
    }

    // Force the profiler to flush events on the main thread.
    void ForceFlush() {
        if (sinks.size() == 0 || event_buffer[current_buffer].size() == 0) {
            return;
        }
        while (is_flushing) {}
        for (auto& sink : sinks) {
            sink->flush(event_buffer[current_buffer], base_line);
        }
        event_buffer[current_buffer].clear();
    }

    // Turns the profiler on.
    void start() {
        is_profiling = true;
    }
    // Turns the profiler off.  Flushing won't occur either currently.
    // At least until ForceFlush is called or the process exits.
    void stop() {
        is_profiling = false;
    }

    // Profiler owns the sink.  This is not thread safe.
    void AddSink(Sink* sink) {
        sinks.emplace_back(sink);
    }

    // This is not strictly enforced.  Default is 5 seconds.
    void SetFlushFrequency(MS milliseconds) {
        if (milliseconds.count() > 0)
            flush_freq = milliseconds;
    }
};

class Timer
{
    int event_idx = -1;
    bool is_stopped = false;
    time_point start_time;
    time_point stop_time;

public:

    using initializer_list_type = std::initializer_list<std::pair<const char*, MetricVariant>>;

    template<typename F>
    Timer& measure(F&& func) {
#ifdef NWNX_PROFILER_ENABLED
        if (profiler && event_idx != -1) {
            start();
            func();
            stop();
        }
#else
        func();
#endif
        return *this;
    }

    // Reset start time.
    void start() {
#ifdef NWNX_PROFILER_ENABLED
        if (profiler && event_idx != -1) {
            is_stopped = false;
            start_time = clock::now();
        }
#endif
    }

    // Stop timer.
    void stop() {
#ifdef NWNX_PROFILER_ENABLED
        if (profiler && event_idx != -1 && !is_stopped) {
            is_stopped = true;
            stop_time = clock::now();
        }
#endif
    }

    Timer& tags(std::initializer_list<std::pair<const char*, MetricVariant>> stuff) {
#ifdef NWNX_PROFILER_ENABLED
        if (profiler && event_idx != -1) {
            for (auto& it : stuff) {
                (*profiler)[event_idx].args.emplace_back(it.first, std::move(const_cast<MetricVariant&>(it.second)), true);
            }
        }
#endif
        return *this;
    }
    Timer& fields(std::initializer_list<std::pair<const char*, MetricVariant>> stuff) {
#ifdef NWNX_PROFILER_ENABLED
        if (profiler && event_idx != -1) {
            for (auto& it : stuff) {
                (*profiler)[event_idx].args.emplace_back(it.first, std::move(const_cast<MetricVariant&>(it.second)), false);
            }
        }
#endif
        return *this;
    }

    // Note whatever you pass in to fields and tags best to be rvalues, possible undefined behavior
    // if not.
    Timer(const char* n, initializer_list_type fields_list = {}, initializer_list_type tags_list = {}) {
#ifdef NWNX_PROFILER_ENABLED
        if (!profiler) {
            return;
        }
        if ((event_idx = profiler->AcquireEventIndex()) != -1) {
            (*profiler)[event_idx].name = n;
            fields(fields_list);
            tags(tags_list);
        }
#endif
    }

    // Note whatever you pass in to fields and tags best to be rvalues, possible undefined behavior
    // if not.
    template <class Rep, class Period>
    Timer(const char* n, time_point& last_sample, const std::chrono::duration<Rep, Period>& sample_period,
          initializer_list_type field_list = {}, initializer_list_type tags_list = {}) {
#ifdef NWNX_PROFILER_ENABLED
        const auto now = clock::now();

        if (now - last_sample < sample_period) {
            return;
        }
        last_sample = now;
        if ((event_idx = profiler->AcquireEventIndex()) != -1) {
            (*profiler)[event_idx].name = n;
            fields(field_list);
            tags(tags_list);
        }
#endif
    }

    ~Timer() {
#ifdef NWNX_PROFILER_ENABLED
        if (profiler && event_idx != -1) {
            if (!is_stopped) stop();
            (*profiler)[event_idx].ts_start = start_time;
            (*profiler)[event_idx].ts_end = stop_time;
            profiler->ReleaseEventIndex();
        }
#endif
    }

    Timer(const Timer&) = delete;
    Timer operator=(const Timer&) = delete;
    Timer(Timer&&) = delete;
    Timer operator=(Timer &&) = delete;
};

struct ScopedTimer : private Timer {
    ScopedTimer(const char* n, Timer::initializer_list_type fields = {}, Timer::initializer_list_type tags = {})
        : Timer(n, fields, tags) {
        start();
    }

    template <class Rep, class Period>
    ScopedTimer(const char* n, time_point& last_sample, const std::chrono::duration<Rep, Period>& sample_period,
                Timer::initializer_list_type fields = {}, Timer::initializer_list_type tags = {})
        : Timer(n, last_sample, sample_period, fields, tags) {
        start();
    }

    ~ScopedTimer() {
        stop();
    }
};

}

#ifdef NWNX_PROFILER_ENABLED
#define NWNX_PROFILE(name, ...) \
    Profiler::ScopedTimer _nwnx_timer(name, ##__VA_ARGS__)
#else
#define NWNX_PROFILE(...)
#endif

#pragma GCC pop_options

