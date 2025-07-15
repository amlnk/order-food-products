#include <stdio.h>
#include <string.h>
#include "cart.h"
#include "menu.h"

void initCart(Cart* cart) {
    cart->count = 0;
}

void addToCart(Cart* cart) {
    int choice;

    showMenu();
    printf("Your choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 0) return;

    if (cart->count >= MAX_ITEMS) {
        printf("Cart is full!\n");
        return;
    }

    switch (choice) {
        case 1:
            strcpy(cart->items[cart->count].name, "Margherita Pizza");
            cart->items[cart->count].price = 120;
            break;
        case 2:
            strcpy(cart->items[cart->count].name, "Chicken Burger");
            cart->items[cart->count].price = 95;
            break;
        case 3:
            strcpy(cart->items[cart->count].name, "Sushi Set");
            cart->items[cart->count].price = 220;
            break;
        default:
            printf("Invalid choice.\n");
            return;
    }

    cart->count++;
    printf("Dish added to the cart.\n");
}

void viewCart(Cart* cart) {
    printf("\n=== CART ===\n");
    if (cart->count == 0) {
        printf("Cart is empty.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < cart->count; i++) {
        printf("%d. %s - %.2f UAH\n", i + 1, cart->items[i].name, cart->items[i].price);
        total += cart->items[i].price;
    }
    printf("Total amount: %.2f UAH\n", total);
}

void checkout(Cart* cart) {
    if (cart->count == 0) {
        printf("Cart is empty, nothing to checkout.\n");
        return;
    }

    viewCart(cart);
    printf("Processing your order...\n");
    printf("Thank you for your order!\n");
    cart->count = 0;
}