#include "NWNXLib.h"

CNWSCreature *nwn_GetCreatureByID(uint32_t id) {
    CGameObject *ob = nwn_GetObjectByID(id);
    return ob ? ob->vtable->AsNWSCreature(ob) : NULL;
}

// Source nwnx_funcs
void nwn_ActionUseItem(CNWSCreature *cre, CNWSItem* it, CNWSObject *target, CNWSArea* area,
                       CScriptLocation *loc, int prop){

    CNWSCreature__UseItem(cre, it->obj.obj_id, prop, 0, target->obj_id, loc->loc_position,
                          area->area_obj_id);
}

// Source nwnx_funcs
void nwn_AddKnownFeat(CNWSCreature *cre, uint16_t feat, uint32_t level){
    if ( !cre || !cre->cre_stats ) { return; }
    
    if (level > 0){
        CNWSStats_Level *ls = nwn_GetLevelStats(cre->cre_stats, level);
        if ( !ls ) { return; }
        CExoArrayList_uint16_add(&(ls->ls_featlist), feat);
    }

    CNWSCreatureStats__AddFeat(cre->cre_stats, feat);
}

// Source nwnx_funcs
int nwn_AddKnownSpell(CNWSCreature *cre, uint32_t sp_class, uint32_t sp_id, uint32_t sp_level){
    int i;

    if ( cre == NULL            ||
         cre->cre_stats == NULL ||
         sp_level < 0 || sp_level > 9 ){
        return -1;
    }

    /* find the requested class and level, then add the new spell */
    for ( i = 0; i < cre->cre_stats->cs_classes_len; i++ ) {
        if ( cre->cre_stats->cs_classes[i].cl_class != sp_class ) {
            continue;
        }

        if ( cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].alloc < 1 ) {
            cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len  = 0;
            cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data = NULL;
        }

        CExoArrayList_uint32_add(&(cre->cre_stats->cs_classes[i].cl_spells_known[sp_level]), sp_id);

        return cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len;
    }

    return -1;
}

uint32_t nwn_CalculateSpellDC(CNWSCreature *cre, uint32_t spellid){
    return CNWSCreature__CalculateSpellSaveDC(cre, spellid);
}

bool nwn_CanUseSkill(CNWSCreature* cre, uint8_t skill) {
    if ( !cre || !cre->cre_stats ) { return false; }
    return CNWSCreatureStats__GetCanUseSkill(cre->cre_stats, skill);
}

void nwn_DecrementFeatRemainingUses(CNWSCreatureStats *stats, uint16_t feat) {
    CNWSCreatureStats__DecrementFeatRemainingUses(stats, feat);
}

int8_t nwn_GetAbilityModifier(CNWSCreatureStats *stats, int8_t abil, bool armorcheck) {
    int8_t mod = 0;
    
    switch ( abil ) {
    case ABILITY_STRENGTH:
        mod = stats->cs_str_mod;
        break;
    case ABILITY_DEXTERITY:
        mod = CNWSCreatureStats__GetDEXMod(stats, armorcheck);
        break;
    case ABILITY_CONSTITUTION:
        mod = stats->cs_con_mod;
        break;
    case ABILITY_WISDOM:
        mod = stats->cs_wis_mod;
        break;
    case ABILITY_INTELLIGENCE:
        mod = stats->cs_int_mod;
        break;
    case ABILITY_CHARISMA:
        mod = stats->cs_cha_mod;
        break;
    }

    return mod;
}

int nwn_GetAttacksPerRound(CNWSCreatureStats *stats){
    return CNWSCreatureStats__GetAttacksPerRound(stats);
}

int8_t nwn_GetBaseSavingThrow(CNWSCreature *cre, uint32_t type) {
    CNWSCreatureStats *stats = cre->cre_stats;
    int8_t result = 0;
    int hd = 0;
    int i;
    for ( i = 0; i < stats->cs_classes_len; ++i ) {
        int cls = stats->cs_classes[i].cl_class;
        hd += stats->cs_classes[i].cl_level;
        CNWClass *c = &(*NWN_Rules)->ru_classes[cls];
        int level = nwn_GetLevelByClass(stats, cls);
        switch ( type ) {
        case SAVING_THROW_FORT:
            result += c->cl_save_fort[level];
        case SAVING_THROW_REFLEX:
            result += c->cl_save_reflex[level];
        case SAVING_THROW_WILL:
            result += c->cl_save_will[level];
        }
    }
    int epic = hd - 20;
    if ( epic <= 0 ) { return result; }

    switch ( type ) {
    case SAVING_THROW_FORT:
        result += CTwoDimArrays__GetEpicFortSaveBonus((*NWN_Rules)->ru_2das, epic);
    case SAVING_THROW_REFLEX:
        result += CTwoDimArrays__GetEpicRefSaveBonus((*NWN_Rules)->ru_2das, epic);
    case SAVING_THROW_WILL:
        result += CTwoDimArrays__GetEpicWillSaveBonus((*NWN_Rules)->ru_2das, epic);
    }

    return result;
	
}

// From nwnx_funcs
int nwn_GetBonusSpellSlots(CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level){
    int i, slots = 0;

    if (cre == NULL                                       ||
        cre->cre_stats == NULL                            ||
        sp_level < 0 || sp_level > 9) {
        return 0;
    }

    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_bonus[sp_level];
        break;
    }
    
    return slots;
}

int32_t nwn_GetDexMod(CNWSCreatureStats *stats, bool armor_check){
    return CNWSCreatureStats__GetDEXMod(stats, armor_check);
}

uint16_t nwn_GetDamageFlags(CNWSCreature *cre) {
    return CNWSCreature__GetDamageFlags(cre);
}

bool nwn_GetEffectImmunity(CNWSCreature *cre, int type, CNWSCreature *vs) {
    return CNWSCreatureStats__GetEffectImmunity(cre->cre_stats, type, vs);
}

bool nwn_GetHasFeat(CNWSCreatureStats *stats, uint16_t feat) {
    return CNWSCreatureStats__HasFeat(stats, feat);
}

int32_t nwn_GetHasNthFeat(CNWSCreature *cre, uint16_t start, uint16_t stop) {
    int32_t n = stop - start;
    while ( n >= 0 && !nwn_GetHasFeat(cre->cre_stats, n + start) ) {
        --n;
    }

    return n + 1;
}

uint32_t nwn_GetHitDice(CNWSCreature *cre) {
    uint32_t res = 0;
    size_t i = 0;

    for ( i = 0; i < cre->cre_stats->cs_classes_len; i++ ) {
        res += cre->cre_stats->cs_classes[i].cl_level;
    }

    return res;
}

bool nwn_GetIsVisible(CNWSCreature *cre, nwn_objid_t target){
    CNWVisibilityNode *node = CNWSCreature__GetVisibleListElement(cre, target);
    if ( node == NULL ) { return false; }

    return node->mask & 1;
}

CNWSItem *nwn_GetItemInSlot(CNWSCreature *cre, uint32_t slot) {
    return CNWSInventory__GetItemInSlot(cre->cre_equipment, slot);
}

void nwn_JumpToLimbo(CNWSCreature *cre) {
    CNWSModule *mod = CServerExoAppInternal__GetModule((*NWN_AppManager)->app_server->srv_internal);

    if (cre == NULL                                   ||
        mod == NULL                                   ||
        cre->cre_is_pc                                ||
        cre->cre_stats->cs_is_pc                      ||
        cre->cre_stats->cs_is_dm) {
        return;
    }

    CNWSCreature__RemoveFromArea(cre, 0);
    CNWSModule__AddObjectToLimbo(mod, cre->obj.obj_id);
}

// From nwnx_funcs
int nwn_GetKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx) {
    int i, sp_id = -1;

    if (cre == NULL                                                   ||
        cre->cre_stats == NULL                                        ||
        sp_level < 0 || sp_level > 9 || sp_idx < 0) {

        return -1;
    }


    /* iterate their class list, matching the requested class, then find the
     * requested spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (sp_idx < cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len)
            sp_id = cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data[sp_idx];

        break;
    }

    return sp_id;
}

// From nwnx_funcs
bool nwn_GetKnowsSpell(CNWSCreature *cre, uint32_t sp_class, uint32_t sp_id) {
    int i, j, sp_known = false;

    if (cre == NULL || cre->cre_stats == NULL)
        return false;

    /* iterate their class list, matching the requested class, then iterate the spells
     * known list for that class */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        for (j = 0; j < 10; j++) {
            sp_known = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[j]), sp_id);
            if (sp_known != 0)
                break;
        }

        break;
    }

    return sp_known;
}

// From nwnx_funcs
int nwn_GetMaxSpellSlots (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level) {
    int i, slots = 0;

    if (cre == NULL                                       ||
        cre->cre_stats == NULL                            ||
        sp_level < 0 || sp_level > 9) {

        return 0;
    }


    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_max[sp_level];

        if (slots == 0)
            slots = cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].len;

        break;
    }

    return slots;
}

// From nwnx_funcs
int nwn_GetMemorizedSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx) {
    int i, ret = -1;
    CNWSStats_Spell *sp;

    if (cre == NULL                                                   ||
        cre->cre_stats == NULL                                        ||
        sp_level < 0 || sp_level > 9) {

        return -1;
    }


    /* iterate their class list, matching the requested class, then iterate the spells
     * known list for that class */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if ((sp = cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx]) == NULL)
            break;

        ret = (sp->sp_id & 0xFFFF) | ((sp->sp_meta & 0xFF) << 16) | (sp->sp_ready << 24);
    }

    return ret;
}

int nwn_GetFeatRemainingUses(CNWSCreatureStats *stats, uint16_t feat){
    return CNWSCreatureStats__GetFeatRemainingUses(stats, feat);
}

bool nwn_GetFlanked(CNWSCreature *cre, CNWSCreature *target){
    return CNWSCreature__GetFlanked(cre, target);
}

bool nwn_GetFlatFooted(CNWSCreature *cre){
    return CNWSCreature__GetFlatFooted(cre);
}

bool nwn_GetIsInvisible(CNWSCreature *cre, CNWSObject *obj){
    return CNWSCreature__GetInvisible(cre, obj, 0);
}

double nwn_GetMaxAttackRange(CNWSCreature *cre, nwn_objid_t target){
    return CNWSCreature__MaxAttackRange(cre, target, 0, 0);
}

// From nwnx_funcs
int nwn_GetRelativeWeaponSize(CNWSCreature *cre, CNWSItem *weapon){
    return CNWSCreature__GetRelativeWeaponSize(cre, weapon);
}

int nwn_GetRemainingSpellSlots (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level) {
    int i, slots = 0;
    if (cre == NULL                                       ||
        cre->cre_stats == NULL                            ||
        sp_level < 0 || sp_level > 9) {

        return 0;
    }

    /* iterate their class list, matching the requested class, then get the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        slots = cre->cre_stats->cs_classes[i].cl_spells_left[sp_level];
        break;
    }
    return slots;
}

int8_t nwn_GetSkillRank(CNWSCreature *cre, uint8_t skill, CNWSObject *vs, bool base) {
    return CNWSCreatureStats__GetSkillRank(cre->cre_stats, skill, vs, base);
}

int nwn_GetTotalFeatUses(CNWSCreatureStats *stats, uint16_t feat){
    return CNWSCreatureStats__GetFeatTotalUses(stats, feat);
}

// From nwnx_funcs
int nwn_GetTotalKnownSpells (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level) {
    int i, sp_len = 0;

    if (cre == NULL                                       ||
        cre->cre_stats == NULL                            ||
        sp_level < 0 || sp_level > 9) {

        return 0;
    }

    /* iterate their class list, matching the requested class, then find the
     * requested spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        sp_len = cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len;
        break;
    }

    return sp_len;
}

int nwn_GetTotalNegativeLevels(CNWSCreatureStats *stats) {
    return CNWSCreatureStats__GetTotalNegativeLevels(stats);
}

void nwn_NotifyAssociateActionToggle(CNWSCreature *cre, int32_t mode){
    CNWSCreature__NotifyAssociateActionToggle(cre, mode);
}

// From nwnx_funcs
int nwn_RemoveKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_id) {
    int i;

    if (cre == NULL || cre->cre_stats == NULL) {
        return -1;
    }

    /* Iterate their class list, matching the requested class, then remove the spell
     * from all levels for that class */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len < 1)
            break;

        CNWSCreatureClass__RemoveKnownSpell(&(cre->cre_stats->cs_classes[i]), sp_level, sp_id);

        return cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len;
    }

    return -1;
}

// From nwnx_funcs
int nwn_ReplaceKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_id, uint32_t sp_new) {
    int i, j, k;

    if (cre == NULL || cre->cre_stats == NULL) {
        return -1;
    }

    /* Iterate their class list, matching the requested class, then iterate the spells
     * known list for that class. If the spell is found, remove it. */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        for (j = 0; j < 10; j++) {
            k = CExoArrayList_uint32_contains(&(cre->cre_stats->cs_classes[i].cl_spells_known[j]), sp_id);

            if (k > 0) {
                cre->cre_stats->cs_classes[i].cl_spells_known[j].data[k - 1] = sp_new;

                return j;
            }
        }
    }
    return -1;
}

// From nwnx_funcs
uint8_t nwn_SetAbilityScore(CNWSCreatureStats *stats, int abil, int val){
    if (stats == NULL || val < 0 || val > 255)
        return -1;

    switch (abil) {
    case ABILITY_STRENGTH:
        CNWSCreatureStats__SetSTRBase(stats, val);
        break;

    case ABILITY_DEXTERITY:
        CNWSCreatureStats__SetDEXBase(stats, val);
        break;

    case ABILITY_CONSTITUTION:
        CNWSCreatureStats__SetCONBase(stats, val, 0);
        break;

    case ABILITY_INTELLIGENCE:
        CNWSCreatureStats__SetINTBase(stats, val);
        break;

    case ABILITY_WISDOM:
        CNWSCreatureStats__SetWISBase(stats, val);
        break;

    case ABILITY_CHARISMA:
        CNWSCreatureStats__SetCHABase(stats, val);
        break;
    }
    return val;
}

void nwn_SetActivity(CNWSCreature *cre, int32_t a, int32_t b){
    CNWSCreature__SetActivity(cre, a, b);
}

void nwn_SetAnimation(CNWSCreature *cre, uint32_t anim){
    CNWSCreature__SetAnimation(cre, anim);
}

void nwn_SetCombatMode(CNWSCreature *cre, uint8_t mode){
    CNWSCreature__SetCombatMode(cre, mode, 1);
}

// From nwnx_funcs
int nwn_SetKnownSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx, uint32_t sp_id) {
    int i;

    if (cre == NULL                                                              ||
        cre->cre_stats == NULL                                                   ||
        sp_level < 0 || sp_level > 9 || sp_idx < 0) {

        return -1;
    }

    /* iterate their class list, matching the requested class, then set the
     * requested spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (sp_idx < cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].len)
            cre->cre_stats->cs_classes[i].cl_spells_known[sp_level].data[sp_idx] = sp_id;
        else
            sp_id = -1;

        break;
    }

    return sp_id;
}

// From nwnx_funcs
int nwn_SetMemorizedSpell (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_idx, uint32_t sp_spell, uint32_t sp_meta, uint32_t sp_flags) {
    int i;
    CNWSStats_Spell *sp;

    if (cre == NULL                                   ||
        cre->cre_stats == NULL                        ||
        sp_level < 0 || sp_level > 9 || sp_idx < 0) {

        return -1;
    }

    /* find the requested class, then alter the requested memorized spell */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (sp_idx >= cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].len)
            break;

        if (sp_spell < 0) {
            if (cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx] != NULL)
                free(cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx]); 

            cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx] = NULL;
        } else {
            if ((sp = cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx]) == NULL) {
                if ((sp = (CNWSStats_Spell *)calloc(1, sizeof(*sp))) == NULL)
                    break;

                cre->cre_stats->cs_classes[i].cl_spells_mem[sp_level].data[sp_idx] = sp;
            }

            sp->sp_id     = sp_spell;
            sp->sp_meta   = sp_meta;
            sp->sp_ready  = !!(sp_flags & 1);
            sp->sp_domain = !!(sp_flags & 2);
        }

        return 1;
    }

    return -1;
}

// From nwnx_funcs
int nwn_SetRemainingSpellSlots (CNWSCreature *cre, uint32_t sp_class, uint32_t sp_level, uint32_t sp_slots) {
    int i;

    if (cre == NULL                                                     ||
        cre->cre_stats == NULL                                          ||
        sp_level < 0 || sp_level > 9 || sp_slots < 0 || sp_slots > 99) {
        
        return -1;
    }

    /* iterate their class list, matching the requested class, then set the slots */
    for (i = 0; i < cre->cre_stats->cs_classes_len; i++) {
        if (cre->cre_stats->cs_classes[i].cl_class != sp_class)
            continue;

        if (sp_slots > cre->cre_stats->cs_classes[i].cl_spells_max[sp_level])
            sp_slots = cre->cre_stats->cs_classes[i].cl_spells_max[sp_level];

        cre->cre_stats->cs_classes[i].cl_spells_left[sp_level] = sp_slots;
        break;
    }

    return sp_slots;
}

// Original code From nwnx_chat
void nwn_SendMessage(uint32_t mode, uint32_t id, const char *msg, uint32_t to) {

    if ( to <= 0x7F000000 ) {
        if ( mode == 4 || mode == 5 || mode == 20 || mode == 21 ) {
            return;
        }
        else if ( mode == 6 || mode == 22 ) {
            return;
        }
    }

    if( mode != 4 && mode != 5 && mode != 20 && mode != 21 ) {
        to = -1;
    }
    else {
        CNWSPlayer *pl = nwn_GetPlayerByID(to);
        if (!pl) { return; }
        to = pl->pl_id;
    }

    CNWSMessage* message = CServerExoApp__GetNWSMessage((*NWN_AppManager)->app_server);
    if(message){
        char xz = '\0';
        CExoString s;
        s.text = strdup(msg);

        CNWSMessage__SendServerToPlayerChatMessage(message, mode, id, (const char **)&s, to, &xz);
    }
}
