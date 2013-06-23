
/***************************************************************************
    NWNXFuncs.cpp - Implementation of the CNWNXFuncs class.
    Copyright (C) 2007 Doug Swarin (zac@intertex.net)

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

extern CNWNXLevels levels;

void Func_GetMeetsFeatRequirements (CGameObject *ob, char *value) {
    int ret;
    CNWSCreature *cre;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    if (*value == '>') {
        int i, fr_feat;
        uint8_t ls_skills[SKILL_LAST + 1];
        std::fill_n(ls_skills, SKILL_LAST + 1, 0);
        CExoString var_name;
        char buffer[500];

        CNWSStats_Level ls;
        ls.ls_featlist.data  = NULL;
        ls.ls_featlist.len   = 0;
        ls.ls_featlist.alloc = 0;
        ls.ls_skilllist      = ls_skills;

        //skills
        for(int i = 0; i <= SKILL_LAST; i++){
            sprintf(buffer, "LL_SKILL_%d", i);
            var_name.text = buffer;
            var_name.len = strlen(var_name.text)+1;
            levels.Log(3, "Skill Var Name: |%s|\n", var_name.text);

            ls.ls_skilllist[i] = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
            levels.Log(3, "Skill : %d\n", ls.ls_skilllist[i]);
        }

        //Class
        var_name.text = "LL_CLASS";
        var_name.len = 9;
        int cls = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;
        levels.Log(3, "Class : %d\n", cls);

        // Ability
        var_name.text = "LL_STAT";
        var_name.len = 10;
        int ability = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;
        if (ability < 0 || ability > 5)
            ability = 6;
        levels.Log(3, "Ability : %d\n", ability);

        var_name.text = "LL_FEAT_COUNT";
        var_name.len = 9;
        int feat_count = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
        for (i = 0; i < feat_count; i++){
            sprintf(buffer, "LL_FEAT_%d", i);
            var_name.text = buffer;
            var_name.len = strlen(var_name.text)+1;
            levels.Log(3, "Feat Var Name: |%s|\n", var_name.text);

            CExoArrayList_uint16_add(&ls.ls_featlist, CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1);
            levels.Log(3, "Feat : %d\n", ls.ls_featlist.data[i]);
        }

        if (sscanf(value, ">%d", &fr_feat) != 1) {
            snprintf(value, strlen(value), "0");
            return;
        }

        ls.ls_class   = cls;
        ls.ls_ability = ability;
        ls.ls_hp      = 1;
        ls.ls_epic_level     = 1;
        ret = CNWSCreatureStats__FeatRequirementsMetAfterLevelUp(cre->cre_stats, fr_feat, &ls, 0);
        free(ls.ls_featlist.data);
    } else {
        CExoArrayList_uint16 taken = { NULL, 0, 0 };
        ret = CNWSCreatureStats__FeatRequirementsMet(cre->cre_stats, atoi(value), &taken);

        if (taken.data != NULL) {
            free(taken.data);
            taken.data = NULL;
        }
    }

    snprintf(value, strlen(value), "%d", !!ret);
}


/* vim: set sw=4: */
