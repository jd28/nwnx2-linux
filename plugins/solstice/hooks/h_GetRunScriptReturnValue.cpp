#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;

int32_t rsrv_return;

int Hook_GetRunScriptReturnValue(CVirtualMachine *vm, int* a, void** b){
    solstice.Log(3, "Lua Conditional return value: %d\n", solstice.lua_last_return);
    
    if (solstice.lua_last_return >= 0){
        *a = 3;
        rsrv_return = solstice.lua_last_return;
        *b = &rsrv_return;
        solstice.lua_last_return = -1;
        return 1;
    }
    else if (vm->field_0 == 3){
        *a = 3;
        *b = vm->vm_return_value;
        return 1;
    }
    return 0;
}
