#include <algorithm>
#include <utility>

#define RANGED_TYPE_BOW              1
#define RANGED_TYPE_CROSSBOW         2
#define RANGED_TYPE_THROWAXE         3
#define RANGED_TYPE_SLING            4
#define RANGED_TYPE_DART             5
#define RANGED_TYPE_SHURIKEN         6

#include "talib/effects/creation.h"
#include "Attack.h"

extern CNWNXSolstice solstice;
extern lua_State *L;

static Attack *ATTACK = nullptr;

Attack *Local_GetAttack() {
    return ATTACK;
}

Attack::Attack(CNWSCreature *attacker, CNWSObject *target, bool ranged)
    : attacker_nwn(attacker)
    , target_nwn(target)
    , attacker_ci(nullptr)
    , target_ci(nullptr)
{

    CNWSCombatRound *cr = attacker->cre_combat_round;
    int cur_att = cr->cr_current_attack;
    CNWSCombatAttackData *data = CNWSCombatRound__GetAttack(cr, cur_att);

    data->cad_attack_group = ++cr->cr_attack_group;
    data->cad_target = target->obj_id;
    data->cad_ranged_attack = ranged;
    data->cad_attack_mode = attacker->cre_mode_combat;
    data->cad_attack_type = CNWSCombatRound__GetWeaponAttackType(cr);
    attack = data;

    //solstice.Log(3,
    //             "Attack::update(): Current Attack: %d, Attack Group: %d, "
    //             "Target: %x, Mode: %d, Attack Type: %d, Equip num: %d\n",
    //             cur_att, data->cad_attack_group, data->cad_target,
    //             data->cad_attack_mode, data->cad_attack_type, equip_num_);

    memset(&dmg_result, 0, sizeof(DamageResult));
}

void Attack::resolvePreAttack() {
    ATTACK = this;
    if ( !nl_pushfunction(L, "NWNXSolstice_ResolvePreAttack") ) { return; }
    lua_pushinteger(L, attacker_nwn->obj.obj_id);
    lua_pushinteger(L, target_nwn->obj_id);

    if (lua_pcall(L, 2, 0, 0) != 0){
        solstice.Log(0, "SOLSTICE: NWNXSolstice_ResolvePreAttack : %s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
}

void Attack::resolve() {
    auto item = nwn_GetCurrentAttackWeapon(attacker_nwn, attack->cad_attack_type);
    weapon = EQUIP_TYPE_UNARMED;
    if ( item ) {
        for (int i = 0; i < EQUIP_TYPE_NUM; ++i) {
            if ( attacker_ci->equips[i].id == item->obj.obj_id ) {
                weapon = i;
                break;
            }
        }
    }

    if ( attack->cad_ranged_attack ) {
        if ( !nl_pushfunction(L, "NWNXSolstice_DoRangedAttack") ) { return; }
        if (lua_pcall(L, 0, 0, 0) != 0){
            solstice.Log(0, "SOLSTICE: NWNXSolstice_DoRangedAttack : %s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }
    else {
        if ( !nl_pushfunction(L, "NWNXSolstice_DoMeleeAttack") ) { return; }
        if ( lua_pcall(L, 0, 0, 0) != 0 ) {
            solstice.Log(0, "SOLSTICE: NWNXSolstice_DoMeleeAttack : %s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }
}

uint32_t Attack::resolveAmmo(uint32_t num_attacks, bool equip) {
    CNWSItem *it;
    uint32_t stacksize = 0;
    uint32_t basetype, equipslot;

    //solstice.Log(3, "GetAmmunitionAvailable : Num Attacks: %d, Ranged Type: %d\n",
    //             num_attacks, attacker_->offense.ranged_type);

    // Determine if there is a weapon that has Unlimited Ammo item
    // property.
    it = nwn_GetItemInSlot(attacker_nwn, EQUIPMENT_SLOT_RIGHTHAND);
    if ( it && CNWSItem__GetPropertyByTypeExists(it, 61, 0) ) {
        return num_attacks;
    }

    switch(attacker_ci->offense.ranged_type) {
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

    it = CNWSInventory__GetItemInSlot(attacker_nwn->cre_equipment, equipslot);
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
            id = CItemRepository__FindItemWithBaseItemId(attacker_nwn->cre_inventory, basetype, i);
            //combat.Log(3, "GetAmmunitionAvailable : Item to Equip: %X", id);
            ++i;

            if ( (it = nwn_GetItemByID(id)) != NULL) {
                canequip = CNWSCreature__CanEquipItem(attacker_nwn, it, &basetype, 1, 0, 0, 0);
                CNWSCreature__RemoveItemFromRepository(attacker_nwn, it, 1);
                if(it->it_possessor != attacker_nwn->obj.obj_id) {
                    CNWSItem__SetPossessor(it, attacker_nwn->obj.obj_id, 0, 0, 0);
                }

                if ( equip ) {
                    CNWSCreature__UnequipItem(attacker_nwn, orig_it, 0);
                    CItemRepository__AddItem(attacker_nwn->cre_inventory, &orig_it, -1, -1, 0, 0);
                }

                CNWSCreature__EquipItem(attacker_nwn, equipslot, it, 1, 0);
                stacksize = it->it_stacksize;
                break;
            }
        } while (id != OBJECT_INVALID);
    }

    if ( !equip ) {
        if (stacksize < 20 && attacker_nwn->cre_last_ammo_warning >= stacksize + 5 ){
            attacker_nwn->cre_last_ammo_warning = stacksize;
            CNWCCMessageData *msg = CNWCCMessageData_create();
            CExoArrayList_int32_add(&msg->integers, stacksize);
            CNWSCreature__SendFeedbackMessage(attacker_nwn, 0x18, msg, 0);
        }
    }

    // Can't have more attacks than the final stacksize.
    num_attacks = std::min(num_attacks, stacksize);

    // If we have nothing to attack with, send out the appropriate messages.
    if ( !equip && num_attacks == 0 ){
        if( attacker_nwn->cre_is_pc || CNWSCreature__GetIsPossessedFamiliar(attacker_nwn) ){
            CNWSCreature__SendFeedbackMessage(attacker_nwn, 0x19, 0, 0);
        }
        else if( attacker_nwn->cre_master_id != OBJECT_INVALID ){
            CNWSCreature *master = nwn_GetCreatureByID(attacker_nwn->cre_master_id);
            if( master ) {
                CNWCCMessageData *msg = CNWCCMessageData_create();
                CExoArrayList_uint32_add(&msg->objects, attacker_nwn->obj.obj_id);
                CNWSCreature__SendFeedbackMessage(master, 0xF1, msg, 0);
            }
        }
    }

    //solstice.Log(3, "GetAmmunitionAvailable : Final Attack Count: %d\n", num_attacks);

    return num_attacks;
}

void Attack::resolveNoAmmo() {
    CNWSCombatRound *cr = attacker_nwn->cre_combat_round;
    CNWSCombatRound__SetRoundPaused(cr, 0, OBJECT_INVALID);
    CNWSCombatRound__SetPauseTimer(cr, 0, 0);
    nwn_SetAnimation(attacker_nwn, 1);
}

void Attack::update() {
    CNWSCombatRound *cr = attacker_nwn->cre_combat_round;
    int cur_att = ++cr->cr_current_attack;
    int ranged = attack->cad_ranged_attack;

    CNWSCombatAttackData *data = CNWSCombatRound__GetAttack(cr, cur_att);
    data->cad_ranged_attack = ranged;
    data->cad_attack_group = cr->cr_attack_group;
    data->cad_target = target_nwn->obj_id;
    data->cad_attack_mode = attacker_nwn->cre_mode_combat;
    data->cad_attack_type = CNWSCombatRound__GetWeaponAttackType(cr);
    attack = data;

    memset(&dmg_result, 0, sizeof(DamageResult));
}
