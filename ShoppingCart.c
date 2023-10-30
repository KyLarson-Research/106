#include <stdio.h>

#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase ItP, ShoppingCart SC){
   //use the cart size to identify the empty cart slot
   SC.cartItems[SC.cartSize] = ItP;
   SC.cartSize +=1;//update cart size
   return SC;
}

void swapItem(ItemToPurchase *ItP1, ItemToPurchase *ItP2){
   ItemToPurchase Temp;
   Temp = *ItP1;
   *ItP1 = *ItP2;
   *ItP2 = Temp;
   return;
}

ShoppingCart RemoveItem(char itemName[50], ShoppingCart SC){//removes the first instance of item with itemName
   int i, j;
   for(i =0; i < SC.cartSize; i++){
       if(strcmp(SC.cartItems[i].itemName, itemName) == 0){
          for(j=i; j< SC.cartSize; j++){
             swapItem(&SC.cartItems[j], &SC.cartItems[j+1]);
             }
          break;}
          }
   MakeItemBlank(&SC.cartItems[SC.cartSize - 1]);
   SC.cartSize -=1;
   return SC;
}

ShoppingCart ModifyItem(ItemToPurchase ItP, ShoppingCart SC){
   int i;
   for(i =0 ; i< SC.cartSize; i++){
      if(strcmp(SC.cartItems[i].itemName, ItP.itemName)==0){
         SC.cartItems[i] = ItP;
         }
   }
   return SC;
}

int GetNumItemsInCart(ShoppingCart SC){
   return SC.cartSize;
}

int GetCostOfCart(ShoppingCart SC){
   int total=0, i=0;
   for(i=0; i<SC.cartSize; i++){
      total += SC.cartItems[i].itemQuantity*SC.cartItems[i].itemPrice;
   }
   return total;
}

int PrintTotal(ShoppingCart SC){
    int i, total;
    printf("%s's Shopping Cart - %s\n", SC.customerName, SC.currentDate);
    printf("Number of Items: %d\n\n", SC.cartSize);
    for(i=0; i<SC.cartSize; i++){
       PrintItemCost(SC.cartItems[i]);
       }
    total = GetCostOfCart(SC);
    printf("\nTodal: $%d\n", total);
    return total;
}

void PrintItemDescriptions(ShoppingCart SC){
   int i;
   printf("%s's Shopping Cart - %s\n", SC.customerName, SC.currentDate);
   
   (SC.cartSize == 0) ? printf("SHOPPING CART IS EMPTY\n") : printf("Item Descriptions\n");
   for(i=0; i<SC.cartSize; i++){
      PrintItemDescription(SC.cartItems[i]);
   }
   return;
}
