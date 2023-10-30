#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#define MAX_BUF 50
#define MAX_SLT 10
typedef struct ShoppingCart{
   char customerName[MAX_BUF];
   char currentDate[MAX_BUF];
   ItemToPurchase cartItems[MAX_SLT];
   int cartSize;
}ShoppingCart;

ShoppingCart AddItem(ItemToPurchase ItP, ShoppingCart SC);
void swapItem(ItemToPurchase *ItP1, ItemToPurchase *ItP2);
ShoppingCart RemoveItem(char itemName[50], ShoppingCart SC);
ShoppingCart ModifyItem(ItemToPurchase ItP, ShoppingCart SC);
int GetNumItemsInCart(ShoppingCart SC);
int GetCostOfCart(ShoppingCart SC);
int PrintTotal(ShoppingCart SC);
void PrintDescriptions(ShoppingCart SC);

#endif
