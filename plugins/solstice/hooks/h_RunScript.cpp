#include "NWNXSolstice.h"

extern lua_State *L;
extern CNWNXSolstice solstice;

int lua_script = 0;
char *running_script = NULL;
int is_condition;

__attribute__((noinline))
static void local_run_script(CExoString *script, nwn_objid_t oid) {
    lua_script = 0;
    if(script == NULL || script->text == '\0')
        return;

    solstice.Log(4, "SOLSTICE: Script Name: |%s| on %d\n", script->text, oid);


#ifdef NS_PROFILE_SCRIPTS

    if(running_script != NULL)
        free(running_script);

    running_script = strdup(script->text);
    profiler_start_timer(script->text, 0);
#endif

    lua_script = Local_RunLuaScript(script->text, oid);

}

__attribute__((noinline))
static void local_runscript_end(){
}

int Hook_RunScriptStart(CVirtualMachine *vm, CExoString *script, nwn_objid_t id, int a) {
    vm->vm_object_id[vm->vm_recursion_level] = id;
    vm->vm_valid_obj[vm->vm_recursion_level] = a;
    vm->vm_implementer->vmc_object_id = id;

    local_run_script(script, id);

    if (lua_script == 1){
        solstice.Log(0, "SCRIPT: %s, : Result: %d, Return: %d, Cond: %d\n", script->text, lua_script, solstice.lua_last_return,
                     solstice.in_conditional_script);
        return solstice.in_conditional_script;
    }
    else if (lua_script == 0) {
        return CVirtualMachine__RunScript(vm, script, id, a);
    }

    return 0;
}

void Hook_RunScriptEnd(void){
    asm("leave");

    local_runscript_end();

    asm("lea -0xC(%ebp),%esp");
    asm("pop %ebx");
    asm("pop %esi");
    asm("pop %edi");
    //asm("pop %ebp");
    asm("push $0x08262532");
    asm("ret");
}
