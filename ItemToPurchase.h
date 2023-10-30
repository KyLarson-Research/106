#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H


typedef struct ItemToPurchase{
   int itemPrice;
   int itemQuantity;
   char itemName[50];
   char itemDescription[50];
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase *ItP);
void PrintItemCost(ItemToPurchase ItP);
void PrintItemDescription(ItemToPurchase ItP);
#endif
