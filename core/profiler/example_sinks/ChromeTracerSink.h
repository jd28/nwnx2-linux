#pragma once

#include "../Profiler.h"
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <stack>
#include <boost/io/detail/quoted_manip.hpp>

#pragma GCC push_options
#pragma GCC optimize ("-O3")

static void write_event(std::fstream& out, const Profiler::Event& ev, char ph, Profiler::time_point base_line) {
    // [TODO] Fix this mess.
    const char* cat = strchr(ev.name, '.');
    std::string s(ev.name, cat ? cat - ev.name : 0);
    std::string name;
    if(cat) {
        name = std::string(cat + 1, strlen(ev.name) - (cat - ev.name) - 1);
    } else {
        name = ev.name;
    }
    out << "\"cat\":" << boost::io::quoted(s) << ","
        << "\"pid\":" << 0 << ','
        << "\"tid\":" << 0 << ','
        << "\"ts\":" << (ph != 'E' ? Profiler::to_us(ev.ts_start - base_line) : Profiler::to_us(ev.ts_end - base_line)) << ','
        << "\"ph\":\"" << ph << "\","
        << "\"name\": " << boost::io::quoted(name) << ',';
    if(ph == 'X') {
        out << "\"dur\":"
            << Profiler::to_ns(ev.ts_end-ev.ts_start) / 1000.0 << ',';
    }

    out << "\"args\":";
    bool first_arg = true;
    if(ev.args.size() > 0 && ph != 'E') {
        out << "{";
        for(const auto& arg : ev.args) {
            out << (first_arg ? "" : ",\n");
            out << boost::io::quoted(arg.name) << ":";
            switch(arg.value.type) {
            default:
                out << "";
                break;
            case Profiler::MetricVariant::Types::INT:
                out << arg.value.a_int;
                break;
            case Profiler::MetricVariant::Types::STRING:
                out << boost::io::quoted(arg.value.a_string);
                break;
            case Profiler::MetricVariant::Types::STRING_SHORT:
                char temp[17];
                memcpy(temp, arg.value.a_string_short, 16);
                temp[16] = 0;
                out << boost::io::quoted(temp);
                break;
            case Profiler::MetricVariant::Types::DOUBLE:
                out << arg.value.a_double;
                break;
            }
            first_arg = false;
        }
        out << "}";
    }
    else {
        out << "{}";
    }
}

static std::stack<std::vector<Profiler::Event>::const_iterator> ev_stack;

class ChromeTracerSink : public Profiler::Sink {
    std::fstream out;
    bool first_line = true;

    void new_file() {
        std::stringstream ss;
        time_t now = std::time(0);
        ss << "nwserver.trace." << now << ".json";
        out.open(ss.str().c_str(), std::ios_base::out);
        if(out.is_open())
            out << "{\"traceEvents\":[\n"
                << "{\"cat\":\"\",\"pid\":0,\"tid\":0,\"ts\":6,\"ph\":\"M\",\"name\":\"process_name\",\"args\":{\"name\":\"nwserver\"}},\n"
                << "{\"cat\":\"\",\"pid\":0,\"tid\":0,\"ts\":10,\"ph\":\"M\",\"name\":\"thread_name\",\"args\":{\"name\":\"main thread\"}},\n";
    }

public:
    ChromeTracerSink() {
        new_file();
    }

    virtual void flush(const std::vector<Profiler::Event>& events, Profiler::time_point base_line);

    ~ChromeTracerSink() {
        out << "\n]}";
    }
};

void ChromeTracerSink::flush(const std::vector<Profiler::Event> &events, Profiler::time_point base_line) {
    if(!out.is_open()) {
        return;
    }

    for(auto it = events.begin(); it < events.end(); ++it) {
        while(ev_stack.size() > 0 && ev_stack.top()->ts_end < it->ts_start)  {
            out << (first_line ? "{" : ",\n{");
            write_event(out, *ev_stack.top(), 'E', base_line);
            ev_stack.pop();
            out << '}';
        }

        out << (first_line ? "{" : ",\n{");

        char ph;
        if(it != events.end()-1 && it->ts_end < (it+1)->ts_start) {
            ph = 'X';
        }
        else {
            ph = 'B';
            ev_stack.push(it);
        }
        write_event(out, *it, ph, base_line);
        out << '}';

        first_line = false;
    }

    while(ev_stack.size() > 0)  {
        out << (first_line ? "{" : ",\n{");
        write_event(out, *ev_stack.top(), 'E', base_line);
        ev_stack.pop();
        out << '}';
    }
    if(out.tellg() > 20971520u) {
        out << "\n]}";
        out.close();
        new_file();
        first_line = true;
    }
}
#pragma GCC pop_options
