#ifndef TALIB_ITEM_H
#define TALIB_ITEM_H

CNWSItem        *nwn_GetItemByID(uint32_t id);
uint8_t          nwn_GetItemSize(CNWSItem *item);
CNWItemProperty *nwn_GetPropertyByType(CNWSItem *item, uint16_t type);
bool             nwn_HasPropertyType(CNWSItem *item, uint16_t type);
CNWBaseItem     *nwn_GetBaseItem(uint32_t basetype);
void             nwn_DestroyItem(CNWSItem *it);

#endif // TALIB_ITEM_H
