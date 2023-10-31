#include<stdio.h>
#include<string.h>
 

#include "ItemToPurchase.h"


void MakeItemBlank(ItemToPurchase *ItP){
   strcpy(ItP->itemName, "none");
   strcpy(ItP->itemDescription, "none");
   ItP->itemPrice = 0;
   ItP->itemQuantity = 0;
   return;
}

void PrintItemCost(ItemToPurchase ItP){
   printf("%s", ItP.itemName);
   printf(" %d @", ItP.itemQuantity);
   printf(" $%d = $%d\n", ItP.itemPrice, ItP.itemQuantity*(ItP.itemPrice));
   return;

}
 
void PrintItemDescription(ItemToPurchase ItP){
   printf("%s: %s\n", ItP.itemName, ItP.itemDescription);
   return;
}



