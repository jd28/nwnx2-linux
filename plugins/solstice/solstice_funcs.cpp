#include "solstice_funcs.h"
#include "NWNXLib.h"
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

extern char* running_script;
extern CNWNXSolstice solstice;

void ns_DelayCommand(uint32_t objid, float delay, uint32_t token){
    CVirtualMachineScript *vms = NULL;
    vms = (CVirtualMachineScript *) malloc(sizeof (CVirtualMachineScript));

    if (running_script == NULL){
        solstice.Log(3, "LUAJIT: WARNING running_script is null!\n");
    }

    // delay command: $
    // We only need to save the running script name for profiling
    // purposes.
#ifdef NWNX_LUAJIT_PROFILE
    char temp[18];
    sprintf(temp, "$%s", running_script);
    vms->vms_name.text = strdup(temp);
#else
    vms->vms_name.text = strdup(COMMAND_MARKER_DELAY);
#endif
    vms->vms_stack = NULL;
    vms->vms_code = NULL;
    vms->vms_stack_size = token;

    nwn_DelayCommand(objid, delay, vms);

    solstice.Log(3, "id: %x, delay: %.2f, token: %d, scriptsit: %s\n",
                 objid, delay, vms->vms_stack_size,
                 vms->vms_name.text);

}

void ns_RepeatCommand(uint32_t objid, float delay, uint32_t token){
    CVirtualMachineScript *vms = NULL;
    vms = (CVirtualMachineScript *) malloc(sizeof (CVirtualMachineScript));

    if (running_script == NULL){
        solstice.Log(3, "LUAJIT: WARNING running_script is null!");
    }

    // delay command: $
    // We only need to save the running script name for profiling
    // purposes.
#ifdef NWNX_LUAJIT_PROFILE
    char temp[18];
    sprintf(temp, "*%s", running_script);
    vms->vms_name.text = strdup(temp);
#else
    vms->vms_name.text = strdup(COMMAND_MARKER_REPEAT);
#endif
    vms->vms_stack = NULL;
    vms->vms_code = NULL;
    vms->vms_stack_size = token;

    nwn_DelayCommand(objid, delay, vms);

    solstice.Log(3, "id: %x, delay: %.2f, token: %d, scriptsit: %s",
                 objid, delay, vms->vms_stack_size,
                 vms->vms_name.text);
}

void ns_ActionDoCommand(CNWSObject * obj, uint32_t token){
    if(obj->obj_type == OBJECT_TYPE_AREA || !obj->obj_is_commandable)
        return;

    CVirtualMachineScript *vms = NULL;
    vms = (CVirtualMachineScript *) malloc(sizeof (CVirtualMachineScript));

    // delay command: $
    char temp[17]; // = (char*) malloc(strlen(running_script)+1 * sizeof(char));
    sprintf(temp, "&%s", running_script);
    vms->vms_stack = NULL;
    vms->vms_code = NULL;
    vms->vms_stack_size = token;
    vms->vms_name.text = strdup(temp);

    nwn_DoCommand(obj, vms);

    return;
}

int ns_BitScanFFS(uint32_t mask) {
    return __builtin_ffs(mask) - 1;
}
