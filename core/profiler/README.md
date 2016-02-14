## NWNX Profiler

##### What is this?

A generic profiling framework.

##### How do I use this?

The best way is to use a plugin that will load the sink(s) you want, or create your own.

Pass `-DNWNX_PROFILER_ENABLED` to cmake.

##### What is the overhead?

Depends on how much you want to profile.  Generally speaking, probably not much.  All
profiling data is flushed on a separate thread.  If you pass strings fields/tags that
are over 16 characters, there will be an allocation when the profiler is enabled.

##### What are the limitations?

You can only profile things on the main thread.

### Timers

#### `Timer`

A timer records a start/end timestamp and stores two sets of optional key pairs.  The key pairs
are split into two categories:

* **Fields** - Fields are always data points; those you wish to
  see in a graph afterwards.
  Think of these as what goes into avg(), mean(), sum(), etc.

* **Tags** - Tags are "context"; for example, if profiling a script,
  a tag named "script" would contain the script to execute.
  Think of this as a "group by" in sql lingo.

Ultimately how the the distinction is interpreted is up to the `Profiler::Sink`.

##### Examples

Using start/stop:
```c++

Profiler::Timer t{ "name",
    { { "Optional",  "fields" } },
    { { "Optional", "tags"} }
};
// ...
t.start();
// Some code to time.
t.stop();

// If necessary to add fields or tags after.  These functions can be called as many times as you
// like.  Note that if you use a ScopedTimer, these will be counted by the timer.
t.fields({{ "some bit of info", " not present before code ran." }});
t.tags({{ "some bit of info", " not present before code ran." }});

// ...
// If stop hasn't been called explicitly, it will be when the Timer goes out of scope.
```

Using `Timer::measure`.
```c++

Profiler::Timer{ "name",
    { { "Optional",  "fields" } },
    { { "Optional", "tags"} }
}.measure([&]() {
    // Some code to time.  start and stop are called implicitly.
    // If the profiler is disabled the lambda WILL still be called.
});

```

Using sampling:
```c++
static Profiler::time_point last_sample;
static const Profiler::MS sample_period{10000}; // Only sampled ever 10 seconds.
void func() {
    // Can use Profiler::ScopedTimer as well.
    Profiler::Timer t{ "name", last_sample, sample_period,
        { { "Optional",  "fields" } },
        { { "Optional", "tags"} }
    };
    t.start();
    // Some code...
    t.stop();
}

```

Using chaining:

```c++

Profiler::Timer{"name"}.measure([&]() {
    // Some code to time.  start and stop are called implicitly.
    // If the profiler is disabled the lambda WILL still be called.
}).fields({
    { /* fields */ }
}).tags({
    { /* tags */ }
});
```

### `ScopedTimer`

`ScopedTimer` is a wrapper around `Timer` that calls `Timer::start()` in its constructor and
`Timer::stop()` in its destructor.

#### Examples

```c++
// ...
{
    Profiler::ScopedTimer timer{"name",
        { { "Optional",  "fields" } },
        { { "Optional", "tags"} }
    };
    // ...
} // stop implicitly called.

// ...
```

`NWNX_PROFILE` is also provided as a wrapper around `ScopedTimer`.  Note that it can currently only be used in one scope.

## Sinks

Inherit from `Profiler::Sink` and do whatever you please.  There are a couple examples included.