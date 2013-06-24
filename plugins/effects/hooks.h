/***************************************************************************
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

#ifndef NWNX_EFFECTS_HOOKS_H
#define NWNX_EFFECTS_HOOKS_H

extern int (*CServerAIMaster__OnEffectApplied_orig)(CServerAIMaster *, CNWSObject *, CGameEffect *, int32_t);
extern int (*CServerAIMaster__OnEffectRemoved_orig)(CServerAIMaster *, CNWSObject *, CGameEffect *);

void Hook_CExoArrayList_CGameEffect_Insert(CExoArrayList_ptr *list, CGameEffect *eff, int location);
int32_t Hook_ExecuteCommandApplyEffectOnObject(CNWVirtualMachineCommands*, int32_t, int32_t);
int Hook_OnApplyModifyNumAttacks(CNWSEffectListHandler *ai, CNWSObject *obj, CGameEffect *eff, int a);
int Hook_OnRemoveModifyNumAttacks(CNWSEffectListHandler *ai, CNWSObject *obj, CGameEffect *eff);
void Hook_RemoveBadEffects(CNWSCreature *cre);

bool hook_functions();

#endif // NWNX_EFFECTS_HOOKS_H
