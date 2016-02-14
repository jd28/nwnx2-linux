#pragma once
/* This is a very simple test file sink. Example output:

category: NWNX name: MainLoop dur: 434us
    + category: NWNX name: Hook_RunScriptSituation dur: 392us
      Arguments (2):
        script: mod_load
        object: 0
        + category: NWNX!RESMAN name: CExoResMan__GetKeyEntry_hook dur: 119us
          Arguments (2):
            resref: mod_load
            restype: 2010
        + category: NWNX!RESMAN name: CExoResMan__Demand_hook dur: 33us
          Arguments (2):
            resref: mod_load
            restype: 2010
        + category: NWNX name: Hook_RunScript dur: 198us
          Arguments (2):
            script: mod_init_areas
            object: 1395
            + category: NWNX!RESMAN name: CExoResMan__GetKeyEntry_hook dur: 59us
              Arguments (2):
                resref: mod_init_areas
                restype: 2010
            + category: NWNX!RESMAN name: CExoResMan__Demand_hook dur: 29us
              Arguments (2):
                resref: mod_init_areas
                restype: 2010
*/

#include "../Profiler.h"
#include <fstream>
#include <stack>
#include <iomanip>

class FileSink : public Profiler::Sink {
    std::fstream f;
    std::stack<Profiler::time_point> tstack;
    void indent(std::ostream& out, int level, bool add_plus) {
        for(int i = 0; i < level*4; ++i) {
            out << ' ';
        }
        if(add_plus) {
            out << "+ ";
        }
    }

public:
    FileSink() {
        f.open("nwserver.profile.txt", std::ios_base::out);
    }
    ~FileSink() {
        if(f.is_open()) {
            f.close();
        }
    }
    FileSink(const FileSink&) = delete;
    FileSink& operator=(const FileSink&) = delete;

    virtual void flush(const std::vector<Profiler::Event>& events, Profiler::time_point base_line) override {
        if(!f.is_open()) {
            return;
        }
        for(auto& ev : events) {
            while(tstack.size() > 0 && tstack.top() < ev.ts_start)  {
                tstack.pop();
            }
            indent(f, tstack.size(), tstack.size() > 0);
            f << " name: " << ev.name
              << " dur: " << (ev.ts_end - ev.ts_start).count() << "ns"
              << " start: " << std::fixed << std::showpoint << std::setprecision(2)
              << Profiler::to_ms(ev.ts_start - base_line)
              << "ms\n";

            if (ev.args.size()) {
                indent(f, tstack.size(), false);
                f << "  Arguments (" << ev.args.size() << "):" << std::endl;
                for(auto& arg : ev.args) {
                    indent(f, tstack.size(), false);
                    f << "    " << arg.name << ": " << arg.value << "\n";
                }
            }
            tstack.push(ev.ts_end);
        }
    }
};
