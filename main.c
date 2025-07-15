// main.c

#include <stdio.h>
#include "menu.h"
#include "cart.h"

int main() {
    Cart cart;
    initCart(&cart);

    int choice;

    while (1) {
        printf("\n=== FOOD ORDER SERVICE ===\n");
        printf("1. Add dish to cart\n");
        printf("2. View cart\n");
        printf("3. Checkout\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addToCart(&cart);
                break;
            case 2:
                viewCart(&cart);
                break;
            case 3:
                checkout(&cart);
                break;
            case 0:
                printf("Thank you! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
