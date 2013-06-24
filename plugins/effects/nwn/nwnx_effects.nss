const int NWNX_EFFECTS_EVENT_APPLY        = 0;
const int NWNX_EFFECTS_EVENT_REMOVE       = 1;

void NWNXEffects_LogEffects(object oObj = OBJECT_SELF) {
    SetLocalString(oObj, "NWNX!EFFECTS!LOGEFFECTS", "");
}

void NWNXEffects_SendEffects(object oObj = OBJECT_SELF) {
    SetLocalString(oObj, "NWNX!EFFECTS!SENDEFFECTS", "");
}

int NWNXEffects_GetEffectImmunity(int nImmunityType, object oCreature = OBJECT_SELF,
                                  object oVersus = OBJECT_INVALID) {

    string param = IntToString(nImmunityType) + " ";
    param += ObjectToString(oCreature) + " ";
    param += ObjectToString(oCreature);
    
    SetLocalString(oCreature, "NWNX!EFFECTS!GETIMMUNITY", sParam);
    return StringToInt(GetLocalString(oCreature, "NWNX!EFFECTS!SGETIMMUNITY"));
}

int SetCustomEffectHandler(int nEffectType, string sScript){
    // No point in setting the handler to an empty string.
    if (sScript == "")
        return -1;

    string sParam = IntToString(nEffectType) + " " + sScript; 
    SetLocalString(GetModule(), "NWNX!EFFECTS!SETEFFECTHANDLER", sParam);
    return StringToInt(GetLocalString(GetModule(), "NWNX!EFFECTS!SETEFFECTHANDLER"));
}

