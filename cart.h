#ifndef CART_H
#define CART_H

#define MAX_ITEMS 100 
typedef struct {
    char name[50];
    float price;
} FoodItem;

typedef struct {
    FoodItem items[MAX_ITEMS];
    int count;
} Cart;


void initCart(Cart* cart);
void addToCart(Cart* cart);
void viewCart(Cart* cart);
void checkout(Cart* cart);

#endif