#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ItemToPurchase.h"
#include "ItemToPurchase.c"
int main(void) {
 
   /* Type your code here */  
   const int maxbuf =50;
   int price1, price2, qty1, qty2, allocA, allocB;
   char buf1[maxbuf], buf2[maxbuf], c, s[maxbuf];
   
   printf("Item 1\nEnter the item name:\n");
   fflush(stdin);
   fgets(buf1, sizeof(buf1), stdin);
   for(int i=0; i<maxbuf; i++){//make sure it is a string
      if(buf1[i]=='\n'){
         buf1[i] = '\0';
      }
   }
   printf("Enter the item price:\n");
   scanf("%d", &price1);
   printf("Enter the item quantity:\n");
   scanf("%d", &qty1);
   fflush(stdin);
   fgets(s, sizeof(s), stdin);
   //require an aditional new line to begin the next item entry
   c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
   printf("Item 2\nEnter the item name:\n");
   fflush(stdin);
   fgets(buf2, sizeof(buf2), stdin);
   for(int i=0; i<maxbuf; i++){//make sure it is a string
      if(buf2[i]=='\n'){
         buf2[i] = '\0';
      }
   }
   printf("Enter the item price:\n");
   scanf("%d", &price2);
   printf("Enter the item quantity:\n");
   scanf("%d", &qty2);
   printf("\n");
   allocA = sizeof(ItemToPurchase) + (strlen(buf1)+1) * sizeof(char);//required when contains flexible array 
   ItemToPurchase *A  = (ItemToPurchase *)malloc(allocA);
   allocB = sizeof(ItemToPurchase) + (strlen(buf2)+1) * sizeof(char);
   ItemToPurchase *B  = (ItemToPurchase *)malloc(allocB);//this is required when flexible
   
   MakeItemBlank(A);
   MakeItemBlank(B);
   
   strcpy(A->itemName, buf1);
   A->itemPrice = price1;
   A->itemQuantity = qty1;
   
   strcpy(B->itemName, buf2);
   B->itemPrice = price2;
   B->itemQuantity = qty2;
   
   printf("TOTAL COST\n");
   PrintItemCost(A);
   PrintItemCost(B);
   printf("\nTotal: $%d\n", (A->itemPrice) * (A->itemQuantity) + (B->itemPrice) * (B->itemQuantity));

   
   free(A);
   free(B);
   return 0;
}
