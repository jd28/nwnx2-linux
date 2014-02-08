#include "NWNXSolstice.h"
#include "funcs.h"

extern CNWNXSolstice solstice;

char* HandleRequest(CGameObject *ob, const char *request, char *value) {
#define M(str, lit)                                                     \
    strncmp((str), "" lit, (sizeof (lit)/sizeof(char)) - 1) == 0

    if( M(request, "LOADCONSTANTS") ){
        Func_LoadConstants(ob, value);
    }
    else if( M(request, "REMOVEFROMCACHE") ){
        Func_RemoveObjectFromCache(ob, value);
    }

    return NULL;
#undef M
}
