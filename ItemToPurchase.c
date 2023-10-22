#include<stdio.h>
#include<string.h>
 

#include "ItemToPurchase.h"


void MakeItemBlank(ItemToPurchase *ItP){
   strcpy(ItP->itemName, "none");
   ItP->itemPrice = 0;
   ItP->itemQuantity = 0;
   return;
}

void PrintItemCost(ItemToPurchase *ItP){
   printf("%s", ItP->itemName);
   printf(" %d @", ItP->itemQuantity);
   printf(" $%d = %d", ItP->itemPrice, ItP->itemQuantity*(ItP->itemPrice));
   return;

}

