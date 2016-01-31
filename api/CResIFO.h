#ifndef _CRESIFO_H_
#define _CRESIFO_H_
#include "nwndef.h"
#include "CRes.h"

class CResIFO : CRes
{
public:
    ~CResIFO();
    uint32_t field_0;
    CResGFF *Gff;
    CResRef ResRef;
    /* 0x18/24 */ unsigned long ModuleVTable;
};
#endif
