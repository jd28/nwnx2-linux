#include "NWNXCombat.h"

extern CNWNXCombat combat;

volatile CNWSItem *weapon;

__attribute__((noinline))
static int local(CNWSItem *item){
    C2DA *props = nwn_GetCached2da(WEAPON_PROP_2DA);
    if ( !item || !props ) { return false; }
    
    return !!nwn_Get2daInt(props, "Monk", 
                           combat.baseitem_to_weapon(item->it_baseitem));
}
    
void Hook_GetIsFlurryWeapon() {
    asm ("leave");
    asm ("movl %esi, weapon");
    
    local((CNWSItem *)weapon);
       
    asm ("push $0x080f998C");
    asm ("ret");
}
