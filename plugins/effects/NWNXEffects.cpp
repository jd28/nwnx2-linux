/***************************************************************************
    Copyright (C) 2013 jmd (jmd2028 at gmail dot com)

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

#include "NWNXEffects.h"

extern PLUGINLINK *pluginLink;

int (*CExoArrayList__CGameEffect_Add)(CExoArrayList_ptr *list, CGameEffect *eff) = NULL;

CNWNXEffects::CNWNXEffects() {
    confKey = strdup("EFFECTS");
}

CNWNXEffects::~CNWNXEffects() {}

void CNWNXEffects::EffectEvent(CNWSObject *obj, CGameEffect *eff, bool removal) {
    effect_event.obj = obj;
    effect_event.eff = eff;
    effect_event.is_remove = removal;
    effect_event.delete_eff = false;

    Log(3, "Effect Event: Object: %x, Effect: %d, Removal: %d\n",
        obj->obj_id, eff->eff_type, removal);

    int notifyRet = NotifyEventHooks(hOnEffectEvent, (WPARAM)&effect_event, 0);
}


void CNWNXEffects::CustomEffectEvent(CNWSObject *obj, CGameEffect *eff, bool removal) {
    custom_effect_event.obj = obj;
    custom_effect_event.eff = eff;
    custom_effect_event.is_remove = removal;
    custom_effect_event.delete_eff = false;

    Log(3, "Custom Effect Event: Object: %x, Effect: %d, Removal: %d\n",
        obj->obj_id, eff->eff_integers[1], removal);

    int notifyRet = NotifyEventHooks(hOnCustomEffectEvent, (WPARAM)&custom_effect_event, 0);
}

char *CNWNXEffects::OnRequest (char *gameObject, char *Request, char *Parameters) {
    Log(1, "StrReq: \"%s\"\nParams: \"%s\"\n", Request, Parameters);

    Log(1, "Return: \"%s\"\n", Parameters);

    return NULL;
}


unsigned long CNWNXEffects::OnRequestObject (char *gameObject, char *Request) {
    unsigned long ret = OBJECT_INVALID;
    Log(1, "ObjReq: \"%s\"\n", Request);
    Log(1, "Return: %08X\n", ret);

    return ret;
}


bool CNWNXEffects::OnCreate (gline *config, const char *LogDir) {
    char log[128];
    sprintf(log, "%s/nwnx_effects.txt", LogDir);

    /* call the base class create function */
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    // Plugin Events
    if(!pluginLink){
        Log (0, "Plugin link not accessible\n");
    }
    else {
        Log (0, "Plugin link: %08lX\n", pluginLink);

        hOnEffectEvent = CreateHookableEvent("NWNX/Effects/EffectEvent");
        hOnCustomEffectEvent = CreateHookableEvent("NWNX/Effects/CustomEffectEvent");
    }

    hook_functions();
    talib_init();
    *(int*)&CExoArrayList__CGameEffect_Add = 0x08061028;

    return true;
}
