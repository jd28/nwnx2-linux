#include "Profiler.h"
#include <ostream>
#include <iomanip>

std::unique_ptr<Profiler::Profiler> profiler;

namespace Profiler {
std::ostream &operator<<(std::ostream &out, const MetricVariant &arg) {
    switch(arg.type) {
    default:
        break;
    case MetricVariant::Types::INT:
        out << arg.a_int;
        break;
    case MetricVariant::Types::STRING:
        out << arg.a_string;
        break;
    case MetricVariant::Types::STRING_SHORT:
        char temp[17];
        memcpy(temp, arg.a_string_short, 16);
        temp[16] = 0;
        out << temp;
        break;
    case MetricVariant::Types::DOUBLE:
        out << arg.a_double;
        break;
    }

    return out;
}

MetricVariant::MetricVariant(MetricVariant &&other) {
    type = other.type;
    other.type = Types::NONE;
    switch(type) {
    default:
        break;
    case Types::INT:
        a_int = other.a_int;
        other.a_int = 0;
        break;
    case Types::STRING:
        a_string = other.a_string;
        other.a_string = 0;
        break;
    case Types::STRING_SHORT:
        memcpy(a_string_short, other.a_string_short, 16);
    case Types::DOUBLE:
        a_double = other.a_double;
        other.a_double = 0;
        break;
    }
}

MetricVariant& MetricVariant::operator=(MetricVariant &&other) {
    if(type == Types::STRING && a_string) {
        free(a_string);
    }
    type = other.type;
    other.type = Types::NONE;
    switch(type) {
    default:
        break;
    case Types::INT:
        a_int = other.a_int;
        other.a_int = 0;
        break;
    case Types::STRING:
        a_string = other.a_string;
        other.a_string = 0;
        break;
    case Types::STRING_SHORT:
        memcpy(a_string_short, other.a_string_short, 16);
    case Types::DOUBLE:
        a_double = other.a_double;
        other.a_double = 0;
        break;
    }
    return *this;
}
/*
ArgumentVariant::ArgumentVariant(const ArgumentVariant &other)
{
    type = other.type;
    switch(type) {
    default: break;
    case Types::INT: a_int = other.a_int; break;
    case Types::STRING: a_string = strdup(other.a_string); break;
    case Types::STRING_SHORT: memcpy(a_string_short, other.a_string_short, 16);
    case Types::FLOAT: a_float = other.a_float; break;
    case Types::DOUBLE: a_double = other.a_double; break;
    case Types::OBJECT: a_object = other.a_object; break;
    }
}

ArgumentVariant& ArgumentVariant::operator=(const ArgumentVariant &other)
{
    if(this != &other) {
        if(type == Types::STRING && a_string) { free(a_string); }
        type = other.type;
        switch(type) {
        default: break;
        case Types::INT: a_int = other.a_int; break;
        case Types::STRING: a_string = strdup(other.a_string); break;
        case Types::STRING_SHORT: memcpy(a_string_short, other.a_string_short, 16);
        case Types::FLOAT: a_float = other.a_float; break;
        case Types::DOUBLE: a_double = other.a_double; break;
        case Types::OBJECT: a_object = other.a_object; break;
        }
    }
    return *this;
}
*/
}
