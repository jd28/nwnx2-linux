#include "NWNXLib.h"

void nwn_DelayCommand(uint32_t obj_id, double delay, CVirtualMachineScript *vms){
    uint32_t day, time;
    CWorldTimer *timer = (*NWN_AppManager)->app_server->srv_internal->srv_time_world;
    day = CWorldTimer__GetCalendarDayFromSeconds(timer, delay);
    time = CWorldTimer__GetTimeOfDayFromSeconds(timer, delay);

    CServerAIMaster *ai_master = (*NWN_AppManager)->app_server->srv_internal->srv_ai;
    int result = CServerAIMaster__AddEventDeltaTime(ai_master, day, time, obj_id,
                                                    obj_id, EVENT_TIMED_EVENT, vms);
    if ( result == 0 ) {
        nx_log(NX_LOG_INFO, 0, "DelayCommand Error: %d", result);
    }
}

void nwn_DeleteLocalFloat(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__DestroyFloat(vt, &name);
}

void nwn_DeleteLocalInt(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__DestroyInt(vt, &name);
}

void nwn_DeleteLocalLocation(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__DestroyLocation(vt, &name);
}

void nwn_DeleteLocalObject(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__DestroyObject(vt, &name);
}

void nwn_DeleteLocalString(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__DestroyString(vt, &name);
}

void nwn_DoCommand(CNWSObject *obj, CVirtualMachineScript *vms) {
    CNWSObject__AddAction(obj, 37, 65535, 5, vms, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

CGameEffect* nwn_GetEffect (const CNWSObject *obj, const nwn_objid_t eff_creator,
                            const int eff_spellid, const int eff_type, const int eff_int0, const int eff_int1){
    int i;
    CGameEffect *eff;
    for (i = 0; i < obj->obj_effects_len; i++) {
        if ((eff = obj->obj_effects[i]) == NULL)
            continue;

        if(eff->eff_type > eff_type)
            return NULL;

        if (eff_creator != OBJECT_INVALID && eff->eff_creator != eff_creator)
            continue;

        if (eff_spellid >= 0 && eff->eff_spellid != eff_spellid)
            continue;

        if (eff_type >= 0 && eff->eff_type != eff_type)
            continue;

        if (eff_int0 != 0 && eff->eff_integers[0] != eff_int0)
            continue;

        if (eff_int1 != 0 && eff->eff_integers[1] != eff_int1)
            continue;

        return eff;
    }
    return NULL;
}



int nwn_GetHasEffect (const CNWSObject *obj, const nwn_objid_t eff_creator,
                      const int eff_spellid, const int eff_type, const int eff_int0){
    int i;
    const CGameEffect *eff;
    for (i = 0; i < obj->obj_effects_len; i++) {
        if ((eff = obj->obj_effects[i]) == NULL)
            continue;

        // Effect list is sorted.
        if(eff->eff_type > eff_type)
            break;

        nx_log(NX_LOG_INFO, 0, "Type: %d", eff->eff_type);

        if (eff_creator != OBJECT_INVALID && eff->eff_creator != eff_creator)
            continue;

        if (eff_spellid >= 0 && eff->eff_spellid != eff_spellid)
            continue;

        if (eff_type >= 0 && eff->eff_type != eff_type)
            continue;

        if (eff_int0 != 0 && eff->eff_integers[0] != eff_int0)
            continue;

        return 1;
    }
    return 0;

}

int32_t nwn_GetLocalInt(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    return CNWSScriptVarTable__GetInt(vt, &name);
}
float nwn_GetLocalFloat(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    return CNWSScriptVarTable__GetFloat(vt, &name);
}



CScriptLocation nwn_GetLocalLocation(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    return CNWSScriptVarTable__GetLocation(vt, &name);
}

uint32_t nwn_GetLocalObject(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    return CNWSScriptVarTable__GetObject(vt, &name);
}

const char * nwn_GetLocalString(CNWSScriptVarTable *vt, const char *var_name){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    return CNWSScriptVarTable__GetString(vt, &name).text;
}

CScriptVariable *nwn_GetLocalVariableByPosition (CNWSScriptVarTable *vt, int idx) {
    if (vt == NULL || idx < 0) {
        return NULL;
    }

    if (idx >= vt->vt_len) {
        return NULL;
    }

    return &vt->vt_list[idx];
}

bool nwn_GetLocalVariableSet(CNWSScriptVarTable *vt, const char *var_name, int8_t type){
    if (vt == NULL || var_name == NULL || type < 0) {
        return false;
    }

    size_t i;
    for(i = 0; i < vt->vt_len; i++) {
        if(strcmp(vt->vt_list[i].var_name.text, var_name) == 0
           && vt->vt_list[i].var_type == type){
            return true;
        }
    }

    return false;
}

int nwn_GetLocalVariableCount (CNWSScriptVarTable *vt) {
    return vt->vt_len;
}

void nwn_RemoveEffectById(CNWSObject *obj, uint32_t id){
    CNWSObject__RemoveEffectById(obj, id);
}

void nwn_SetLocalFloat(CNWSScriptVarTable *vt, const char *var_name, float value){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__SetFloat(vt, &name, value);
}

void nwn_SetLocalInt(CNWSScriptVarTable *vt, const char *var_name, int32_t value){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__SetInt(vt, &name, value, 0);
}

void nwn_SetLocalLocation(CNWSScriptVarTable *vt, const char *var_name, CScriptLocation * value){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CScriptLocation new_loc;
    //new_loc.CopyScriptLocation(value);

    CNWSScriptVarTable__SetLocation(vt, &name, new_loc);
}

void nwn_SetLocalObject(CNWSScriptVarTable *vt, const char *var_name, uint32_t id){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CNWSScriptVarTable__SetObject(vt, &name, id);
}

void nwn_SetLocalString(CNWSScriptVarTable *vt, const char *var_name, const char *value){
    CExoString name = {
        .text = (char*)var_name,
        .len  = 0
    };

    CExoString string = {
        .text = (char*)value,
        .len  = 0
    };

    CNWSScriptVarTable__SetString(vt, &name, &string);
}

void nwn_SetTag(CNWSObject *obj, const char *value) {
    if (obj->obj_type == OBJECT_TYPE_MODULE){
        // Skip modules...
        return;
    }
    else if (obj->obj_type == OBJECT_TYPE_AREA){
    	CNWSArea *area = nwn_GetAreaByID(obj->obj_id);
        if ( area ) {
            free(area->area_tag.text);
            area->area_tag.text = strdup(value);
        }
    }
    else {
        free(obj->obj_tag);
        obj->obj_tag = strdup(value);
    }
}
