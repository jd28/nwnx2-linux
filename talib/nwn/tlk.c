#include "NWNXLib.h"

// Not pleased with this...
char *nwn_GetStringByStrref(uint32_t strref) {
    nwn_StackPushInteger(0);
    nwn_StackPushInteger(strref);
    nwn_ExecuteCommand(239, 2);
    char *s = nwn_StackPopString();
    return s;
}
