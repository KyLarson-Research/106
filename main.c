#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ItemToPurchase.h"
#include "ItemToPurchase.c"
#include "ShoppingCart.c"
#include "ShoppingCart.h"

void PrintMenu(){
   printf("MENU\n");
   printf("a - Add item to cart\n");
   printf("r - Remove item from cart\n");
   printf("c - Change item quantity\n");
   printf("i - Output items' descriptions\n");
   printf("o - Output shopping cart\n");
   printf("q - Quit\n");
   printf("\n");
   printf("Choose an option:\n");
   return;
}

ShoppingCart ExecuteMenu(char option, ShoppingCart SC){
   
       switch(option)
       {
          case 'a': //add item to cart
             char s;
             int price, qty;
             ItemToPurchase ItP;
             
             printf("ADD ITEM TO CART\nEnter the item name:\n");
             fflush(stdin);
             fgets(ItP.itemName, sizeof(ItP.itemName), stdin);
             for(int i=0; i<strlen(ItP.itemName); i++){//make sure it is a string
                if(ItP.itemName[i]=='\n'){
                   ItP.itemName[i] = '\0';
                }
             }
             printf("Enter the item description:\n");
             fflush(stdin);
             fgets(ItP.itemDescription, sizeof(ItP.itemDescription), stdin);
             for(int i=0; i<strlen(ItP.itemDescription); i++){//make sure it is a string
                if(ItP.itemDescription[i]=='\n'){
                   ItP.itemDescription[i] = '\0';
                }
             }
             printf("Enter the item price:\n");
             scanf("%d", &ItP.itemPrice);
             printf("Enter the item quantity:\n");
             scanf("%d", &ItP.itemQuantity);//now push it
             if(SC.cartSize!=10){SC.cartItems[SC.cartSize] = ItP; SC.cartSize++;}
             else{printf("CART IS FULL\n");}
          break;
          case 'r': break;
          case 'c': break;
          case 'i': break;//descriptions
          case 'o': break;//shopping cart
          
       }
   return SC;
}

int main(void) {
  
 
 
    
   const int maxbuf =50;
   int price1, price2, qty1, qty2;
   char buf1[maxbuf], buf2[maxbuf], c='y', s; 
   ShoppingCart SC;
   printf("Enter customer's name:\n");
   fflush(stdin);
   fgets(SC.customerName, sizeof(SC.customerName), stdin);
   SC.customerName[strlen(SC.customerName)-1] = '\0'; //remove the new line that gets captured
   printf("Enter today's date:\n");
   scanf("%s", SC.currentDate);
   printf("\nCustomer name: %s\nToday's date: %s\n", SC.customerName, SC.currentDate);
   //require an aditional new line to begin the next item entry
   c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
   
   while(c != 'q'){
      PrintMenu();
      
      scanf("%c", &c);
      s = getchar();
      while(s != '\n' && s != EOF) { s = getchar(); }//filter the extra new line
      
      SC = ExecuteMenu(c, SC);
      
   }
   /*
   //
   ///*Appendix- The following is part 1 and testing
   //
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
   //allocA = sizeof(ItemToPurchase) + (strlen(buf1)+1) * sizeof(char);//required when contains flexible array 
   ItemToPurchase A;//  = (ItemToPurchase *)malloc(allocA);
   A.itemName[0] = '\0';
   //allocB = sizeof(ItemToPurchase) + (strlen(buf2)+1) * sizeof(char);
   ItemToPurchase B;//  = (ItemToPurchase *)malloc(allocB);//this is required when flexible
   B.itemName[0] = '\0';
   MakeItemBlank(&A);
   MakeItemBlank(&B);
   
   strcpy(A.itemName, buf1);
   A.itemPrice = price1;
   A.itemQuantity = qty1;
   
   strcpy(B.itemName, buf2);
   B.itemPrice = price2;
   B.itemQuantity = qty2;
   
   printf("TOTAL COST\n");
   PrintItemCost(A);
   PrintItemCost(B);
   printf("\nTotal: $%d\n", (A.itemPrice) * (A.itemQuantity) + (B.itemPrice) * (B.itemQuantity));
   //Testing Add Item
   
   SC = AddItem(A, SC);
   SC = AddItem(B, SC);
   
   printf("%d cart size, %s item 1, %s item 2\n", SC.cartSize, SC.cartItems[0].itemName, SC.cartItems[1].itemName);
   /*
   printf("Testing Remove Item\n");
   SC = RemoveItem(A.itemName, SC);
   printf("%d cart size, %s first item\n", SC.cartSize, SC.cartItems[0].itemName);
  
   SC = RemoveItem(B.itemName, SC);
   printf("%d cart size\n", SC.cartSize);
   printf("Testing Modify Item\n");
   ItemToPurchase I;
   strcpy(I.itemName, A.itemName);
   I.itemQuantity=A.itemQuantity;
   I.itemPrice=A.itemPrice;
   strcpy(I.itemDescription, "this is a new and improved item");
   SC = ModifyItem(I, SC);
   printf("%s\n", SC.cartItems[0].itemDescription);
   //checking GetNum..() and GetCost..()
   printf("%d cart size, cart total %d\n", GetNumItemsInCart(SC), GetCostOfCart(SC));
   //testing the last two functions
   PrintTotal(SC);
   PrintItemDescriptions(SC);
   //PrintItemDescription(A);
   //PrintItemDescription(B);
   //free(A);
   //free(B);
   */
   return 0;
}
