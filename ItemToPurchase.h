#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H


typedef struct ItemToPurchase{
   int itemPrice;
   int itemQuantity;
   char itemName[];//this has to be the last element of the struct and there may only be one array
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase *ItP);
void PrintItemCost(ItemToPurchase *ItP);

#endif
