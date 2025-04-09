#include <stdio.h>
#include <string.h>

// Define a structure for menu items
struct MenuItem {
    int id;
    char name[50];
    float price;
};

// Function to display available food items
void displayMenu(struct MenuItem menu[], int size) {
    printf("\n--- Available Food Items ---\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - ?%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
    printf("-----------------------------\n");
}

int main() {
    // Initial menu setup
    struct MenuItem menu[] = {
        {1, "Burger", 80.0},
        {2, "Pizza", 150.0},
        {3, "Pasta", 120.0},
        {4, "Fries", 60.0},
        {5, "Cold Drink", 40.0}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    int choice, quantity;
    char moreOrder;
    float totalBill = 0.0;

    printf("======= Welcome to Student's Canteen =======\n");

    do {
        // Display the menu to the user
        displayMenu(menu, menuSize);

        // Asking user to select a food item
        printf("Enter the item number you want to order: ");
        scanf("%d", &choice);

        // Validate choice
        if (choice < 1 || choice > menuSize) {
            printf("Invalid choice! Please choose a valid item from the list.\n");
            continue;
        }

        // Asking for quantity
        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);

        // Calculating total cost
        float itemTotal = menu[choice - 1].price * quantity;
        totalBill += itemTotal;

        printf("You added %d x %s = ?%.2f to your order.\n", quantity, menu[choice - 1].name, itemTotal);

        // Asking if user wants to order more
        printf("Do you want to order more? (y/n): ");
        scanf(" %c", &moreOrder);

    } while (moreOrder == 'y' || moreOrder == 'Y');

    // Final bill display
    printf("\n========= Final Bill =========\n");
    printf("Total Amount to Pay: ?%.2f\n", totalBill);
    printf("Thank you for ordering. Have a nice day!\n");
    

    return 0;
}

