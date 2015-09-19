#include "NWNXLib.h"

char *nwn_GetStringByStrref(uint32_t strref) {
    CExoString s = CTlkTable__GetSimpleString((*NWN_TlkTable), strref);
    return s.text;
}
