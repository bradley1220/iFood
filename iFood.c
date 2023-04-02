#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    int quantity;
    float price;
};

void print_menu(struct item menu[], int n) {
    printf("\n----- MENU -----\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - %.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("----------------\n");
}

int main() {
    struct item menu[] = {

        {"Kebab", 80, 1.50},
        {"Egg chop", 60, 2.50},
        {"Coke", 50, 1.50},
        {"Chips", 100, 0.75},
        {"Burger", 25, 3.50},
        {"Pizza", 20, 4.99},
        {"Ice Cream", 30, 2.00}
    };
    int num_items = sizeof(menu) / sizeof(struct item);

    printf("Welcome to the billing system!\n");
    print_menu(menu, num_items);

    int choice, quantity;
    float total_price = 0;
    char ch;

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        total_price += menu[choice-1].price * quantity;
        menu[choice-1].quantity -= quantity;

        printf("\nDo you want to order anything else? (y/n) ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("\n----- BILL -----\n");
    for (int i = 0; i < num_items; i++) {
        if (menu[i].quantity < 10) {
            printf("%s is running low! Only %d left.\n", menu[i].name, menu[i].quantity);
        }
    }
    printf("----------------\n");
    printf("Total price: $%.2f\n", total_price);

    return 0;
}
