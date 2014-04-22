#include <boost/algorithm/string.hpp>
#include "solstice_funcs.h"
#include "NWNXLib.h"
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

extern char* running_script;
extern CNWNXSolstice solstice;

#define RANGED_TYPE_BOW              1
#define RANGED_TYPE_CROSSBOW         2
#define RANGED_TYPE_THROWAXE         3
#define RANGED_TYPE_SLING            4
#define RANGED_TYPE_DART             5
#define RANGED_TYPE_SHURIKEN         6

void ns_DelayCommand(uint32_t objid, float delay, uint32_t token){
    CVirtualMachineScript *vms = NULL;
    vms = (CVirtualMachineScript *) malloc(sizeof (CVirtualMachineScript));

    if (running_script == NULL){
        solstice.Log(3, "LUAJIT: WARNING running_script is null!\n");
    }

    // delay command: $
    // We only need to save the running script name for profiling
    // purposes.
#ifdef NWNX_LUAJIT_PROFILE
    char temp[18];
    sprintf(temp, "$%s", running_script);
    vms->vms_name.text = strdup(temp);
#else
    vms->vms_name.text = strdup(COMMAND_MARKER_DELAY);
#endif
    vms->vms_stack = NULL;
    vms->vms_code = NULL;
    vms->vms_stack_size = token;

    nwn_DelayCommand(objid, delay, vms);

    solstice.Log(3, "id: %x, delay: %.2f, token: %d, scriptsit: %s\n",
                 objid, delay, vms->vms_stack_size,
                 vms->vms_name.text);

}

void ns_RepeatCommand(uint32_t objid, float delay, uint32_t token){
    CVirtualMachineScript *vms = NULL;
    vms = (CVirtualMachineScript *) malloc(sizeof (CVirtualMachineScript));

    if (running_script == NULL){
        solstice.Log(3, "LUAJIT: WARNING running_script is null!");
    }

    // delay command: $
    // We only need to save the running script name for profiling
    // purposes.
#ifdef NWNX_LUAJIT_PROFILE
    char temp[18];
    sprintf(temp, "*%s", running_script);
    vms->vms_name.text = strdup(temp);
#else
    vms->vms_name.text = strdup(COMMAND_MARKER_REPEAT);
#endif
    vms->vms_stack = NULL;
    vms->vms_code = NULL;
    vms->vms_stack_size = token;

    nwn_DelayCommand(objid, delay, vms);

    solstice.Log(3, "id: %x, delay: %.2f, token: %d, scriptsit: %s",
                 objid, delay, vms->vms_stack_size,
                 vms->vms_name.text);
}

void ns_ActionDoCommand(CNWSObject * obj, uint32_t token){
    if(obj->obj_type == OBJECT_TYPE_AREA || !obj->obj_is_commandable)
        return;

    CVirtualMachineScript *vms = NULL;
    vms = (CVirtualMachineScript *) malloc(sizeof (CVirtualMachineScript));

    // delay command: $
    char temp[17]; // = (char*) malloc(strlen(running_script)+1 * sizeof(char));
    sprintf(temp, "&%s", running_script);
    vms->vms_stack = NULL;
    vms->vms_code = NULL;
    vms->vms_stack_size = token;
    vms->vms_name.text = strdup(temp);

    nwn_DoCommand(obj, vms);

    return;
}

int ns_BitScanFFS(uint32_t mask) {
    return __builtin_ffs(mask) - 1;
}

const char** str_split(const char* s, const char* sep, bool isany) {
    static std::vector<std::string> res;

    res.empty();

    if ( isany ) {
        boost::split(res, s, boost::is_any_of(sep));
    }
    else {
        boost::iter_split(res, s, boost::first_finder(sep));
    }

    const char** array = (const char**)malloc(sizeof(const char*) * (res.size() + 1));

    size_t i = 0;
    for ( const auto& s : res ) {
        array[i] = s.c_str();
        ++i;
    }
    array[res.size()] = NULL;
    return array;
}

const char* str_rtrim(const char* str) {
    static std::string s;
    s = str;
    boost::trim_right(s);
    return s.c_str();
}

const char *str_ltrim(const char* str) {
    static std::string s;
    s = str;
    boost::trim_left(s);
    return s.c_str();
}

const char *str_trim(const char* str) {
    static std::string s;
    s = str;
    boost::trim(s);
    return s.c_str();
}

static void AddOnHitSpell(CNWSCombatAttackData *attack_,
                          CNWSCreature *attacker,
                          CNWSObject *target,
                          CNWItemProperty *ip,
                          uint32_t item_id,
                          bool from_target) {
     if ( !attacker || !target || !ip ||
          ip->ip_type != ITEM_PROPERTY_ONHITCASTSPELL ) {
         return;
     }

     C2DA *tda = (*NWN_Rules)->ru_2das->tda_iprp_onhitspell;
     if ( !tda ) { return; }

     int sp_idx = nwn_Get2daInt(tda, "SpellIndex", ip->ip_subtype);
     solstice.Log(3, "OnHit Spell Index: %d\n", sp_idx);
     solstice.Log(3, "Spell 2da Length: %d\n",
                  (*NWN_Rules)->ru_spells->spa_len);

     CNWSpell *spell;
     if ( sp_idx < 0 || sp_idx > (*NWN_Rules)->ru_spells->spa_len ) {
         return;
     }
     else {
         spell = CNWSpellArray__GetSpell((*NWN_Rules)->ru_spells, sp_idx);
     }

     CNWSSpellScriptData *data = (CNWSSpellScriptData *)malloc(sizeof(CNWSSpellScriptData));
     if ( !data ) { return; }

     data->target_pos.x = 0;
     data->target_pos.y = 0;
     data->target_pos.z = 0;
     data->feat_id      = -1;
     data->item_id      = item_id;
     data->area_id      = attacker->obj.obj_area_id;

     solstice.Log(3, "OnHit Spell Impcat: %s\n", spell->sp_impactscript.text);
     if (!spell->sp_impactscript.text) { return; }
     data->script.text  = strdup(spell->sp_impactscript.text);
     data->script.len   = strlen(spell->sp_impactscript.text);

     if ( from_target ) {
         data->target_id  = attacker->obj.obj_id;
         data->target_pos = attacker->obj.obj_position;
         data->caster_id  = target->obj_id;
         CExoArrayList_ptr_add(&attack_->cad_onhit_spells2, data);
     }
     else {
         data->target_id  = target->obj_id;
         data->target_pos = target->obj_position;
         data->caster_id  = attacker->obj.obj_id;
         CExoArrayList_ptr_add(&attack_->cad_onhit_spells, data);
     }
}


void ns_AddOnHitSpells(CNWSCombatAttackData *data,
                       CNWSCreature *attacker,
                       CNWSObject *target,
                       CNWSItem *item,
                       bool from_target) {

    uint32_t item_id = item->obj.obj_id;
    for ( size_t i = 0; i < item->it_active_ip_len; ++i ) {
        CNWItemProperty& ip = item->it_active_ip[i];
        if ( ip.ip_type != ITEM_PROPERTY_ONHITCASTSPELL ) {
            continue;
        }
        AddOnHitSpell(data,
                      attacker,
                      target,
                      &ip,
                      item_id,
                      from_target);
    }

    for ( size_t i = 0; i < item->it_passive_ip_len; ++i ) {
        CNWItemProperty& ip = item->it_passive_ip[i];
        if ( ip.ip_type != ITEM_PROPERTY_ONHITCASTSPELL ) {
            continue;
        }
        AddOnHitSpell(data,
                          attacker,
                          target,
                          &ip,
                          item_id,
                          from_target);
    }
}

uint32_t ns_GetAmmunitionAvailable(CNWSCreature *attacker, int32_t num_attacks, int32_t ranged_type, bool equip) {
    CNWSItem *it;
    int32_t stacksize = 0;
    uint32_t basetype, equipslot;

    //combat.Log(3, "GetAmmunitionAvailable : Num Attacks: %d, Ranged Type: %d", num_attacks, ranged_type);

    // Determine if there is a weapon that has Unlimited Ammo item
    // property.
    it = nwn_GetItemInSlot(attacker, EQUIPMENT_SLOT_RIGHTHAND);
    if ( it && CNWSItem__GetPropertyByTypeExists(it, 61, 0) ) {
        return num_attacks;
    }

    switch(ranged_type) {
    default: return num_attacks;
    case RANGED_TYPE_BOW:
        equipslot = EQUIPMENT_SLOT_ARROWS;
        basetype  = BASE_ITEM_ARROW;
        break;
    case RANGED_TYPE_SLING:
        equipslot = EQUIPMENT_SLOT_BULLETS;
        basetype  = BASE_ITEM_BULLET;
        break;
    case RANGED_TYPE_CROSSBOW:
        equipslot = EQUIPMENT_SLOT_BOLTS;
        basetype  = BASE_ITEM_BOLT;
        break;
    case RANGED_TYPE_SHURIKEN:
        equipslot = EQUIPMENT_SLOT_RIGHTHAND;
        basetype  = BASE_ITEM_SHURIKEN;
        break;
    case RANGED_TYPE_DART:
        equipslot = EQUIPMENT_SLOT_RIGHTHAND;
        basetype  = BASE_ITEM_DART;
        break;
    case RANGED_TYPE_THROWAXE:
        equipslot = EQUIPMENT_SLOT_RIGHTHAND;
        basetype  = BASE_ITEM_THROWINGAXE;
        break;
    }

    it = CNWSInventory__GetItemInSlot(attacker->cre_equipment, equipslot);
    CNWSItem *orig_it = it;
    if(orig_it) {
        int ss = orig_it->it_stacksize;
        stacksize = equip ? ss - num_attacks : ss;
    }

    // If num_attacks is zero, there is no item, so we'll have to find one.
    if(stacksize <= 0){
        // This is really moronic it seems like to me and should be changed.
        // This is how the default code is tho: traversing the list for each i

        uint32_t i = 0;
        uint32_t id;
        bool canequip;
        do {
            id = CItemRepository__FindItemWithBaseItemId(attacker->cre_inventory, basetype, i);
            //combat.Log(3, "GetAmmunitionAvailable : Item to Equip: %X", id);
            ++i;

            if ( (it = nwn_GetItemByID(id)) != NULL) {
                canequip = CNWSCreature__CanEquipItem(attacker, it, &basetype, 1, 0, 0, 0);
                CNWSCreature__RemoveItemFromRepository(attacker, it, 1);
                if(it->it_possessor != attacker->obj.obj_id) {
                    CNWSItem__SetPossessor(it, attacker->obj.obj_id, 0, 0, 0);
                }

                if ( equip ) {
                    CNWSCreature__UnequipItem(attacker, orig_it, 0);
                    CItemRepository__AddItem(attacker->cre_inventory, &orig_it, -1, -1, 0, 0);
                }

                CNWSCreature__EquipItem(attacker, equipslot, it, 1, 0);
                stacksize = it->it_stacksize;
                break;
            }
        } while (id != OBJECT_INVALID);
    }

    if ( !equip ) {
        if (stacksize < 20 && attacker->cre_last_ammo_warning >= stacksize + 5u ){
            attacker->cre_last_ammo_warning = stacksize;
            CNWCCMessageData *msg = CNWCCMessageData_create();
            CExoArrayList_int32_add(&msg->integers, stacksize);
            CNWSCreature__SendFeedbackMessage(attacker, 0x18, msg, 0);
        }
    }

    // Can't have more attacks than the final stacksize.
    num_attacks = std::min(num_attacks, stacksize);

    // If we have nothing to attack with, send out the appropriate messages.
    if ( !equip && num_attacks == 0 ){
        if( attacker->cre_is_pc || CNWSCreature__GetIsPossessedFamiliar(attacker) ){
            CNWSCreature__SendFeedbackMessage(attacker, 0x19, 0, 0);
        }
        else if( attacker->cre_master_id != OBJECT_INVALID ){
            CNWSCreature *master = nwn_GetCreatureByID(attacker->cre_master_id);
            if( master ) {
                CNWCCMessageData *msg = CNWCCMessageData_create();
                CExoArrayList_uint32_add(&msg->objects, attacker->obj.obj_id);
                CNWSCreature__SendFeedbackMessage(master, 0xF1, msg, 0);
            }
        }
    }

    //combat.Log(3, "GetAmmunitionAvailable : Final Attack Count: %d", num_attacks);

    return num_attacks;
}

void ns_PostPolymorph(CNWSCreature *cre, int32_t ignore_pos, bool is_apply) {
    CNWSCreature__UpdatePersonalSpace(cre);
    CNWSCreature__UpdateAppearanceDependantInfo(cre);

    if ( is_apply ) {
        cre->cre_is_poly = 1;
    }

    if ( !ignore_pos ) {
        CNWSArea *area = CNWSObject__GetArea(&cre->obj);
        if ( area ) {
            Vector new_pos = { 0.0f, 0.0f, 0.0f };
            if ( CNWSArea__ComputeSafeLocation(area,
                                               cre->obj.obj_position,
                                               20.0,
                                               cre->cre_blocked_pos,
                                               1,
                                               &new_pos) ) {
                CNWSObject__SetPosition(&cre->obj, new_pos, 0);
            }
            else {
                new_pos = cre->obj.obj_position;
            }
            cre->cre_is_polymorphing = 1;
            CNWSCreature__RemoveFromArea(cre, 1);
            CNWSCreature__AddToArea(cre, area, new_pos.x, new_pos.y, new_pos.z, 0);
            cre->cre_is_polymorphing = 0;
        }
    }
}
