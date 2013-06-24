/***************************************************************************
    NWNXEffects
    Copyright (C) 2011-2013 jmd ( jmd2028 at gmail dot com )

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

extern CNWNXEffects effects;

int32_t Hook_ExecuteCommandApplyEffectOnObject(CNWVirtualMachineCommands *vm_cmds,
                                               int cmd, int args) {
    int32_t dur_type;
    CGameEffect *eff;
    uint32_t obj_id;
    float duration;

    if ( !CVirtualMachine__StackPopInteger(*NWN_VirtualMachine, &dur_type)                ||
         !CVirtualMachine__StackPopEngineStructure(*NWN_VirtualMachine, 0, (void **)&eff) ||
         !CVirtualMachine__StackPopObject(*NWN_VirtualMachine, &obj_id)                   ||
         !CVirtualMachine__StackPopFloat(*NWN_VirtualMachine, &duration) ) {
        return -639;
    }

    if ( dur_type == 1 ) {
        eff->eff_duration = duration;
    }
    else if ( dur_type < 2 || dur_type > 4 ) {
        dur_type = 0;
    }
    nwn_SetDurationType(eff, dur_type);

    CGameObject *ob = nwn_GetObjectByID(obj_id);
    if ( ob ){
        CGameObject *eff_ob = nwn_GetObjectByID(eff->eff_creator);
        CNWSCreature *cre = ob->vtable->AsNWSCreature(eff_ob);
        if ( cre && cre->cre_item_spell ) {
            eff->field_28 = cre->cre_item_spell_level;
        }

        CNWSObject *object = ob->vtable->AsNWSObject(ob);
        if ( object ) {
            if( eff->eff_type == EFFECT_TRUETYPE_LINK ) {
                object->obj_pending_effect_removal = 1;
            }

            CNWSObject__ApplyEffect(object, eff, 0, 1);
            object->obj_pending_effect_removal = 0;
        }
    }
    else {
        CGameEffect__dtor(eff, 3);
    }

    return 0;
}
