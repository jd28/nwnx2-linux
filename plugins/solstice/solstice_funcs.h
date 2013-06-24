#ifndef _NWNX_SOLSTICE_FUNCS_H_
#define _NWNX_SOLSTICE_FUNCS_H_

#include "NWNXSolstice.h"

#define ENGINE_NUM_STRUCTURES           5
#define ENGINE_STRUCTURE_EFFECT         0
#define ENGINE_STRUCTURE_EVENT          1
#define ENGINE_STRUCTURE_LOCATION       2
#define ENGINE_STRUCTURE_TALENT         3
#define ENGINE_STRUCTURE_ITEMPROPERTY   4

extern "C" {
int  ns_BitScanFFS(uint32_t mask);
void ns_DelayCommand(CNWSObject *obj, float delay, uint32_t token);
void ns_RepeatCommand(CNWSObject *obj, float delay, uint32_t token);    
}
#endif
