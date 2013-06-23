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

extern CNWNXLevels levels;

void Func_LevelUp(CGameObject *ob, char *value) {
    CNWSCreature *cre;
    CExoString var_name;
    char buffer[500];
    int i, j;
    int domain1  = 0;
    int domain2  = 0;
    int wiz_spec = 0;

    if (ob == NULL || (cre = ob->vtable->AsNWSCreature(ob)) == NULL || cre->cre_stats == NULL) {
        snprintf(value, strlen(value), "0");
        return;
    }

    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class == CLASS_TYPE_CLERIC) {
            domain1 = cre->cre_stats->cs_classes[i].cl_domain_1;
            domain2 = cre->cre_stats->cs_classes[i].cl_domain_2;
        }
        if (cre->cre_stats->cs_classes[i].cl_class == CLASS_TYPE_WIZARD) {
            wiz_spec = cre->cre_stats->cs_classes[i].cl_specialist;
        }
    }

    levels.Log(0, "Leveling Up: %x\n", cre->obj.obj_id);

    //Class
    var_name.text = "LL_CLASS";
    var_name.len = 9;
    int cls = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;
    levels.Log(0, "Class : %d\n", cls);
    if (cls < 0) {
        levels.Log(0, "ERROR: Invalid Class : %d\n", cls);
        snprintf(value, strlen(value), "0");
        return;
    }

    //Skill Points
    var_name.text = "LL_SKILL_POINTS";
    var_name.len = 15;
    int skillpoints = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
    levels.Log(0, "Skill Points: %d\n", skillpoints);

    //Hitpoints
    var_name.text = "LL_HP";
    var_name.len = 6;
    int hp = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
    levels.Log(0, "HP: %d\n", hp);

    // Ability
    var_name.text = "LL_STAT";
    var_name.len = 10;
    int ability = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;
    if (ability < 0 || ability > 5)
        ability = 6;
    levels.Log(0, "Ability : %d\n", ability);

    var_name.text = "LL_FEAT_COUNT";
    var_name.len = 9;
    int feat_count = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);

    CNWSStats_Level *ls = (CNWSStats_Level *)malloc(sizeof(CNWSStats_Level));

    ls->ls_class          = cls;
    ls->ls_hp             = hp;
    ls->ls_ability        = ability;
    ls->ls_featlist.data  = 0;
    ls->ls_featlist.len   = 0;
    ls->ls_featlist.alloc = 0;
    ls->ls_skilllist      = (uint8_t*)malloc((SKILL_LAST+1)*sizeof(uint8_t));
    ls->ls_epic_level     = 1;
    ls->ls_skillpoints    = skillpoints;

    levels.Log(0, "Skill Var Name: |%s|\n", var_name.text);

    for(i = 0; i <= SKILL_LAST; i++){
        sprintf(buffer, "LL_SKILL_%d", i);
        var_name.text = buffer;
        var_name.len = strlen(var_name.text)+1;
        levels.Log(3, "Skill Var Name: |%s|\n", var_name.text);

        ls->ls_skilllist[i] = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
        levels.Log(0, "Skill : %d\n", ls->ls_skilllist[i]);
    }

    levels.Log(0, "Feat count: %d\n", feat_count);
    for (i = 0; i < feat_count; i++){
        sprintf(buffer, "LL_FEAT_%d", i);
        var_name.text = buffer;
        var_name.len = strlen(var_name.text)+1;
        int feat = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;
        levels.Log(0, "Feat Var Name: |%s|, Feat: %d\n", var_name.text, feat);

        if (feat < 0) {
            levels.Log(0, "ERROR: Invalid Feat : %d\n", feat);
            snprintf(value, strlen(value), "0");
            return;
        }

        CExoArrayList_uint16_add(&ls->ls_featlist, feat);
        levels.Log(0, "Feat : %d\n", ls->ls_featlist.data[i]);
    }

    int spell;
    for(i = 0; i < 10; i++){
        ls->ls_spells_known[i].data    = 0;
        ls->ls_spells_known[i].len     = 0;
        ls->ls_spells_known[i].alloc   = 0;
        ls->ls_spells_removed[i].data  = 0;
        ls->ls_spells_removed[i].len   = 0;
        ls->ls_spells_removed[i].alloc = 0;
    }

    for(j = 0; j < 10; j++){
        sprintf(buffer, "LL_SPGN%d_USED", j);
        var_name.text = buffer;
        var_name.len = strlen(var_name.text);
        int spell_gain_count = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
        levels.Log(0, "Spells Gained Var Name: |%s|, Count: %d\n", var_name.text, spell_gain_count);
        for(i = 0; i < spell_gain_count; i++){
            sprintf(buffer, "LL_SPGN%d_%d", j, i);
            var_name.text = buffer;
            var_name.len = strlen(var_name.text);

            levels.Log(3, "Spell Gained Var Name: |%s|\n", var_name.text);
            spell = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;

            levels.Log(0, "Spell : %d, Spell Level: %d\n", spell, j);
            if(!ls->ls_spells_known[j].data){
                ls->ls_spells_known[j].data    = (uint32_t*)malloc(sizeof(uint32_t)*spell_gain_count);
                ls->ls_spells_known[j].len     = 0;
                ls->ls_spells_known[j].alloc   = spell_gain_count;
            }

            CExoArrayList_uint32_add(&ls->ls_spells_known[j], spell);
        }
    }


    for(j = 0; j < 10; j++){
        sprintf(buffer, "LL_SPRM%d_USED", j);
        var_name.text = buffer;
        var_name.len = strlen(var_name.text);
        int spell_rem_count = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name);
        levels.Log(0, "Spells Removed Var Name: |%s|, Count: %d\n", var_name.text, spell_rem_count);
        for(i = 0; i < spell_rem_count; i++){
            sprintf(buffer, "LL_SPRM%d_%d", j, i);
            var_name.text = buffer;
            var_name.len = strlen(var_name.text);

            levels.Log(3, "Spell Removed Var Name: |%s|\n", var_name.text);
            spell = CNWSScriptVarTable__GetInt(&cre->obj.obj_vartable, &var_name) - 1;

            levels.Log(0, "Spell : %d, Spell Level: %d\n", spell, j);
            if(!ls->ls_spells_removed[j].data){
                ls->ls_spells_removed[j].data    = (uint32_t*)malloc(sizeof(uint32_t)*spell_rem_count);
                ls->ls_spells_removed[j].len     = 0;
                ls->ls_spells_removed[j].alloc   = spell_rem_count;
            }

            CExoArrayList_uint32_add(&ls->ls_spells_removed[j], spell);
        }
    }

    CNWSCreatureStats__LevelUp(cre->cre_stats, ls, domain1, domain2, wiz_spec, 1);

    snprintf(value, strlen(value), "%d", 1);
}
