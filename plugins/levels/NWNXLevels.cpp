/***************************************************************************
    Copyright (C) 2011-2013 jmd (jmd2028 at gmail dot com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***************************************************************************/

#include "NWNXLevels.h"

CNWNXLevels::CNWNXLevels() {
    confKey = strdup("LEVELS");
}

CNWNXLevels::~CNWNXLevels() { }

char *CNWNXLevels::OnRequest (char *gameObject, char *Request, char *Parameters) {
#define M(str, lit)                                                     \
    strncmp((str), "" lit, (sizeof (lit)/sizeof(char)) - 1) == 0

    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);
    if(strncmp(Request, "LEVELUP", 7) == 0){
        Func_LevelUp((CGameObject *)gameObject, Parameters);
    }
    else if(strncmp(Request, "LEVELDOWN", 9) == 0){
        Func_LevelDown((CGameObject *)gameObject, Parameters);
    }
    else if(strncmp(Request, "GETMAXLEVELLIMIT", 15) == 0){
        Func_GetMaxLevelLimit((CGameObject *)gameObject, Parameters);
    }
    else if(strncmp(Request, "SETMAXLEVELLIMIT", 15) == 0){
        Func_SetMaxLevelLimit((CGameObject *)gameObject, Parameters);
    }
    else if(strncmp(Request, "MODIFYXPDIRECT", 14) == 0){
        Func_ModifyXPDirect((CGameObject *)gameObject, Parameters);
    }
    else if(strncmp(Request, "SETXPDIRECT", 11) == 0){
        Func_SetXPDirect((CGameObject *)gameObject, Parameters);
    }
    else if(M(Request, "GETMEETSFEATREQUIREMENTS")){
        Func_GetMeetsFeatRequirements((CGameObject *)gameObject, Parameters);
    }
    else if(strncmp(Request, "DUMPSPELLS", 10) == 0){
        CGameObject *ob = (CGameObject *)gameObject;
        CNWSCreature *cre;
        CNWSCreatureStats *info;
        int i;

        if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
            snprintf(Parameters, strlen(Parameters), "0");
            return NULL;
        }

        info = cre->cre_stats;
        for(i = 0; i < 10; i++){
            Log(0, "Spelevel: %d, Max: %d, Left: %d\n", i,  info->cs_classes[0].cl_spells_max[i],
                info->cs_classes[0].cl_spells_left[i]);
        }
    }
    else
        Log(0, "Unrecognized string request: \"%s\" \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
#undef M
}

unsigned long CNWNXLevels::OnRequestObject (char *gameObject, char *Request) {
    unsigned long ret = OBJECT_INVALID;

    Log(1, "ObjReq: \"%s\"\n", Request);

    Log(0, "Unrecognized object request: \"%s\"\n", Request);

    Log(1, "Return: %08X\n", ret);

    return ret;
}

bool CNWNXLevels::OnCreate (gline *config, const char *LogDir) {
    char log[128];

    // Function Pointers
    *(int*)&CNWRules__GetFeat = 0x080CB718;
    *(int*)&CNWSCreatureStats__LevelUp = 0x081590F0;
    *(int*)&CNWSScriptVarTable__GetInt = 0x081F3FC8;
    *(int*)&CNWSCreatureStats__LevelDown = 0x08159870;
    sprintf(log, "%s/nwnx_levels.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    talib_init();

    nx_hook_function((void *)0x080BF30C,
                     (void *)Hook_GetSpellGain, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)0x080BF344,
                     (void *)Hook_GetSpellsKnownPerLevel, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)0x0810d628,
                     (void *)Hook_SummonFamiliar, 5, NX_HOOK_DIRECT);
    nx_hook_function((void *)0x0810d1c0,
                     (void *)Hook_SummonAnimalCompanion, 5, NX_HOOK_DIRECT);

    return true;
}
