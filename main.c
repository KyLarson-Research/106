#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ItemToPurchase.h"
#include "ItemToPurchase.c"
int main(void) {
 
   /* Type your code here */  
   ItemToPurchase *A  = (ItemToPurchase *)malloc(sizeof(ItemToPurchase) + 5 * sizeof(char));//this is required when flexible array
   
   MakeItemBlank(A);
   
   PrintItemCost(A);
   free(A);
   return 0;
}
