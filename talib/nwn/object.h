#ifndef TALIB_OBJECT_H
#define TALIB_OBJECT_H

void             nwn_DelayCommand(uint32_t obj_id, double delay, CVirtualMachineScript *vms);

void             nwn_DeleteLocalFloat(CNWSScriptVarTable *vt, const char *var_name);
void             nwn_DeleteLocalInt(CNWSScriptVarTable *vt, const char *var_name);
void             nwn_DeleteLocalLocation(CNWSScriptVarTable *vt, const char *var_name);
void             nwn_DeleteLocalObject(CNWSScriptVarTable *vt, const char *var_name);
void             nwn_DeleteLocalString(CNWSScriptVarTable *vt, const char *var_name);

void             nwn_DoCommand(CNWSObject *obj, CVirtualMachineScript *vms);

CGameEffect*     nwn_GetEffect(const CNWSObject *obj, const nwn_objid_t eff_creator,
                               const int eff_spellid, const int eff_type, const int eff_int0, const int eff_int1);

int              nwn_GetHasEffect(const CNWSObject *obj, const nwn_objid_t eff_creator,
                                  const int eff_spellid, const int eff_type, const int eff_int0);

int32_t          nwn_GetLocalInt(CNWSScriptVarTable *vt, const char *var_name);
float            nwn_GetLocalFloat(CNWSScriptVarTable *vt, const char *var_name);
CScriptLocation  nwn_GetLocalLocation(CNWSScriptVarTable *vt, const char *var_name);
uint32_t         nwn_GetLocalObject(CNWSScriptVarTable *vt, const char *var_name);
const char      *nwn_GetLocalString(CNWSScriptVarTable *vt, const char *var_name);

CScriptVariable *nwn_GetLocalVariableByPosition (CNWSScriptVarTable *vt, int idx);
int              nwn_GetLocalVariableCount (CNWSScriptVarTable *vt);
bool             nwn_GetLocalVariableSet(CNWSScriptVarTable *vt, const char *var_name, int8_t type);

void             nwn_SetLocalFloat(CNWSScriptVarTable *vt, const char *var_name, float value);
void             nwn_SetLocalInt(CNWSScriptVarTable *vt, const char *var_name, int32_t value);
void             nwn_SetLocalLocation(CNWSScriptVarTable *vt, const char *var_name, CScriptLocation * value);
void             nwn_SetLocalObject(CNWSScriptVarTable *vt, const char *var_name, uint32_t id);
void             nwn_SetLocalString(CNWSScriptVarTable *vt, const char *var_name, const char *value);

void             nwn_RemoveEffectById(CNWSObject *obj, uint32_t id);
void             nwn_SetTag(CNWSObject *obj, const char *value);

/*
  void             nwn_DoDamage(void *obj, uint32_t obj_type, int32_t amount);

*/
#endif // TALIB_OBJECT_H
