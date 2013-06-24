#include "profiler.h"
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

typedef struct timeval Time;
typedef struct {
    std::string name;
    Time start;
} EventStack;

typedef struct {
    uint32_t num_calls;
    uint32_t elapsed_time;
    bool updated;
} EventData;

typedef std::unordered_map< std::string, EventData > EventMap;

EventMap event_map;
EventStack event_stack[MAX_CALLDEPTH];
std::ofstream output;

bool PROFILER_DEBUG = true;
int call_depth;
uint32_t event_counter;
uint32_t last_runtime;
bool emptyScript;
bool is_script_situation;
Time last_flush;

static uint32_t get_ms_since(Time now, Time start){
    return (now.tv_sec - start.tv_sec + 1e-6 * (now.tv_usec - start.tv_usec)) / 1000;
}

int profiler_create(const char* file){
    output.open(file, std::ios::out | std::ios::trunc);
    if(!output.is_open())
        std::cout << "Failed to open " << file << ".\n";

    // Performance analysis variables
    event_counter = 0;
    call_depth = -1;
    event_map = EventMap(256);
    gettimeofday(&last_flush, NULL);
    return 1;
}

void profiler_destroy(){
    profiler_flush_stats(0);
    output.flush();
    output.close();
}

void profiler_flush_stats(uint32_t msecs_since_flush){
    if(!output.is_open())
        return;
    // Get current time
    time_t now;
    char strDate[DATEBUFFERLENGTH];
    time(&now);
    strftime(strDate, DATEBUFFERLENGTH, "%c", localtime(&now));
    uint32_t runtime = 0;
	
    output << "\nCurrent statistics\n"
           << "----------------------------------------------------------------\n";

    int col = 0;
    for (EventMap::iterator it = event_map.begin(); it != event_map.end(); it++) {
        if(it->first.empty())
            continue;

        int iMsec = it->second.elapsed_time / 1000;
        output << std::left << std::setw(32) << it->first;

        if (it->second.updated)
            output << std::right
                   << std::setw(10) << iMsec << " msec "
                   << std::setw(6) << it->second.num_calls << " calls *|\n";
        else
            output << std::right
                   << std::setw(10) << iMsec << " msec "
                   << std::setw(6) << it->second.num_calls << " calls  |\n";

        runtime += iMsec;
        it->second.updated = false;
    }

    output << "----------------------------------------------------------------\n"
           << "Elapsed time                : " << msecs_since_flush << " msec\n"
           << "Runtime delta               : " << runtime - last_runtime << " msec\n"
           << "Total cumulative runtime    : " << runtime << " msec\n"
           << "Total number of events      : " << event_counter << "\n"
           << "Current date is             : " << strDate << "\n\n";

    last_runtime = runtime;
}

void profiler_start_timer(char *str, int action){
    if (str != NULL && str != '\0'){
        if (call_depth < MAX_CALLDEPTH - 1)
            call_depth++;
        else
            output << "WARNING : Maximum call depth reached!\n";

        emptyScript = false;
        is_script_situation = false;
        event_stack[call_depth].name = std::string(str);
        event_counter++;

        gettimeofday(&event_stack[call_depth].start, NULL);
    }
    else
        emptyScript = true;
}

void profiler_stop_timer(){
    if (emptyScript || call_depth < 0)
        return;

    EventData ed;

    Time cur;
    gettimeofday(&cur, NULL);

    uint32_t elapsed =  get_ms_since(cur, event_stack[call_depth].start);

    if(PROFILER_DEBUG){
	output << "PROFILER: event: "
	       << event_stack[call_depth].name
	       << ", Call Depth: "
	       << call_depth
	       << "Elapsed Time: "
	       << elapsed
               << "\n";
    }
    EventMap::iterator it = event_map.find(event_stack[call_depth].name);
    if (it == event_map.end()) {
        ed.num_calls = 1;
        ed.elapsed_time = elapsed;
        ed.updated = true;
        event_map.insert(EventMap::value_type(event_stack[call_depth].name, ed));
    }
    else {
        if(!is_script_situation)
            it->second.num_calls++;

        it->second.elapsed_time += elapsed;
        it->second.updated = true;
    }

    uint32_t msecs_since_flush = get_ms_since(cur, last_flush);

    if (msecs_since_flush > 10000){
	gettimeofday(&last_flush, NULL);
	profiler_flush_stats(msecs_since_flush);
    }

    if (call_depth > -1)
	call_depth--;
}
