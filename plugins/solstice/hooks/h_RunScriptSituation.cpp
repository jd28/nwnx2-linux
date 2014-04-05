#include "NWNXSolstice.h"

extern lua_State *L;
extern CNWNXSolstice solstice;
static int run_original;
extern unsigned char d_ret_code_scriptsit_start[0x20];

__attribute__((noinline))
static int local_run_scriptsituation(CVirtualMachineScript *script, nwn_objid_t oid) {
    if(!script || !script->vms_name.text)
        return 1;

    int ctype = -1;
    double result = 0;
    bool repeat = false;

    solstice.Log(3, "Running Script Situation: %s\n",
                 script->vms_name.text);

    if(strncmp(script->vms_name.text, "$", 1) == 0){
        ctype = COMMAND_TYPE_DELAY;
    }
    else if(strncmp(script->vms_name.text, "&", 1) == 0){
        ctype = COMMAND_TYPE_DO;
    }
    else if(strncmp(script->vms_name.text, "*", 1) == 0){
        ctype = COMMAND_TYPE_REPEAT;
    }
    else {
        solstice.Log(4, "Script Situation: |%s| on %x\n", script->vms_name.text, oid);
        return 1;
    }

    uint32_t temp = (*NWN_VirtualMachine)->vm_implementer->vmc_object_id;
    (*NWN_VirtualMachine)->vm_implementer->vmc_object_id = oid;

    if(!nl_pushfunction(L, "_RUN_COMMAND"))
        return 1;

    lua_pushinteger(L, ctype);
    lua_pushinteger(L, script->vms_stack_size);
    lua_pushinteger(L, oid);

    if (lua_pcall(L, 3, 1, 0) != 0){
        solstice.Log(0, "Error: _RUN_COMMAND Type:%d : %s\n", ctype, lua_tostring(L, -1));
        return 1;
    }

    result = lua_tonumber(L, -1);
    lua_pop(L, 1);

    if(ctype == COMMAND_TYPE_REPEAT){
        if(result > 0){
            nwn_DelayCommand(oid, result, script);
            repeat = true;
        }
    }
    if(!repeat){
        free(script->vms_name.text);
        free(script);
    }

    (*NWN_VirtualMachine)->vm_implementer->vmc_object_id = temp;

    return 0;
}

void Hook_RunScriptSituationStart(CVirtualMachine *vm, void *script, uint32_t obj, int a){
    if (!local_run_scriptsituation((CVirtualMachineScript *)script, obj))
        return;

    CVirtualMachine__RunScriptSituation(vm, script, obj, a);
}

__attribute__((noinline))
static void local_runss_end(void){
    //profiler_stop_timer();
}

void Hook_RunScriptSituationEnd(void){
    //08262763
    asm("leave");

    local_runss_end();

    asm("lea -0xC(%ebp),%esp");
    asm("pop %ebx");
    asm("pop %esi");
    asm("pop %edi");
    asm("pop %ebp");
    asm("push $0x0826276A");
    asm("ret");
}
