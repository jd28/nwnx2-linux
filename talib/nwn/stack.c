#include "NWNXLib.h"

void nwn_ExecuteCommand(int command, int num_args){
    CNWVirtualMachineCommands__ExecuteCommand((*NWN_VirtualMachine)->vm_implementer,
                                              command, num_args);
}


uint32_t nwn_GetCommandObjectId(){
    return (*NWN_VirtualMachine)->vm_implementer->vmc_object_id;
}

uint32_t nwn_SetCommandObjectId(uint32_t obj){
    return (*NWN_VirtualMachine)->vm_implementer->vmc_object_id = obj;
}

bool nwn_StackPopBoolean(){
    int result = 0;
    CVirtualMachine__StackPopInteger(*NWN_VirtualMachine, &result);
    return !!result;
}

int32_t nwn_StackPopInteger() {
    int32_t result = 0;
    int32_t err = CVirtualMachine__StackPopInteger(*NWN_VirtualMachine, &result);
    nx_log(NX_LOG_INFO, 3, "StackPopInteger Error: %d, result: %d", err, result);
    return result;
}

float nwn_StackPopFloat(){
    float result = 0.0;
    CVirtualMachine__StackPopFloat(*NWN_VirtualMachine, &result);
    return result;
}

char * nwn_StackPopString(){
    CExoString str = {
        .text = NULL,
        .len  = 0
    };

    int err = CVirtualMachine__StackPopString(*NWN_VirtualMachine, &str);
    nx_log(NX_LOG_INFO, 3, "StackPopString Error: %d", err);
    return str.text;
}

Vector *nwn_StackPopVector(){
    Vector *buf = (Vector *)malloc(sizeof(Vector));
    CVirtualMachine__StackPopVector(*NWN_VirtualMachine, buf);

    return buf;
}

uint32_t nwn_StackPopObject(){
    uint32_t result;
    CVirtualMachine__StackPopObject(*NWN_VirtualMachine, &result);
    return result;
}

void * nwn_StackPopEngineStructure(uint32_t type){
    void *result = NULL;
    if (!CVirtualMachine__StackPopEngineStructure(*NWN_VirtualMachine, type, &result))
        return NULL;
    return result;
}

void nwn_StackPushBoolean(bool value){
    nwn_StackPushInteger(*NWN_VirtualMachine, !!value);
}

void nwn_StackPushInteger(int32_t value){
    int err = CVirtualMachine__StackPushInteger(*NWN_VirtualMachine, value);
    nx_log(NX_LOG_INFO, 3, "StackPopInteger Error: %d, result: %d", err, value);
}

void nwn_StackPushFloat(float value){
    CVirtualMachine__StackPushFloat(*NWN_VirtualMachine, value);
}

void nwn_StackPushString(const char *value){
    CExoString cs = {
        .text = (char*)value,
        .len  = 0
    };
    CVirtualMachine__StackPushString(*NWN_VirtualMachine, &cs);
}

void nwn_StackPushVector(Vector *value){
    CVirtualMachine__StackPushVector(*NWN_VirtualMachine, *value);
}

void nwn_StackPushObject(uint32_t value){
    CVirtualMachine__StackPushObject(*NWN_VirtualMachine, value);
}

void nwn_StackPushEngineStructure(uint32_t type, void * value){
    CVirtualMachine__StackPushEngineStructure(*NWN_VirtualMachine, type, value);
}
