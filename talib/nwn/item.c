#include "NWNXLib.h"

CNWSItem *nwn_GetItemByID(uint32_t id) {
    CGameObject *ob = nwn_GetObjectByID(id);
    return ob ? ob->vtable->AsNWSItem(ob) : NULL;
}

uint8_t nwn_GetItemSize(CNWSItem *item) {
    int bi = item->it_baseitem;
    uint8_t result = 0;
    if ( bi >= 0 && bi < (*NWN_Rules)->ru_baseitems->bitemarray_len ) {
        result = (*NWN_Rules)->ru_baseitems->bitemarray_bitem[bi].bi_size;
    }

    return result;
}

// TODO add subtype back
CNWItemProperty *nwn_GetPropertyByType(CNWSItem *item, uint16_t type) {
    int i;
    CNWItemProperty *ip;

    for ( i = 0; i < item->it_active_ip_len; ++i ) {
        ip = (CNWItemProperty *)&item->it_active_ip[i];
        if ( ip->ip_type == type ) {
            return ip;
        }
    }

    for ( i = 0; i < item->it_passive_ip_len; ++i ) {
        ip = (CNWItemProperty *)&item->it_passive_ip[i];
        if ( ip->ip_type == type ) {
            return ip;
        }
    }
    return NULL;
}

// TODO add subtype back
bool nwn_HasPropertyType(CNWSItem *item, uint16_t type){
    int i;
    CNWItemProperty *ip;

    for ( i = 0; i < item->it_active_ip_len; ++i ) {
        ip = (CNWItemProperty *)&item->it_active_ip[i];
        if ( ip->ip_type == type ) {
            return true;
        }
    }

    for ( i = 0; i < item->it_passive_ip_len; ++i ) {
        ip = (CNWItemProperty *)&item->it_passive_ip[i];
        if ( ip->ip_type == type ) {
            return true;
        }
    }

    return false;
}

CNWBaseItem *nwn_GetBaseItem(uint32_t basetype){
    CNWBaseItemArray *basearr = (*NWN_Rules)->ru_baseitems;
    if (basetype >= 0 && basetype < basearr->bitemarray_len)
        return &basearr->bitemarray_bitem[basetype];

    return NULL;
}

void nwn_DestroyItem(CNWSItem *it) {
    it->obj.obj_vtable->destructor(&it->obj, 3);
}
