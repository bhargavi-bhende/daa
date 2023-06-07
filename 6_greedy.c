#include <stdio.h>

typedef struct {
    int weight;
    int value;
    double ratio;  // New member for value-to-weight ratio
} Item;

double fractionalKnapsack(int knapsackCapacity, Item items[], int numItems);

int knapsack_01(int knapsackCapacity, Item items[], int numItems) {
    // Sort the items based on value in descending order
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            if (items[j].value < items[j + 1].value) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    int selectedItems[numItems];
    for (int i = 0; i < numItems; i++) {
        selectedItems[i] = 0;
    }

    int currentWeight = 0;

    // Select items for the knapsack in a greedy manner
    for (int i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= knapsackCapacity) {
            selectedItems[i] = 1;
            currentWeight += items[i].weight;
        }
    }

    // Print the selected items and their total value
    int totalValue = 0;
    printf("Selected items:\n");
    for (int i = 0; i < numItems; i++) {
        if (selectedItems[i]) {
            printf("Item %d (Weight: %d, Value: %d)\n", i + 1, items[i].weight, items[i].value);
            totalValue += items[i].value;
        }
    }

    return totalValue;
}

double fractionalKnapsack(int knapsackCapacity, Item items[], int numItems) {
    // Calculate the value-to-weight ratio for each item
    for (int i = 0; i < numItems; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    // Sort the items based on the value-to-weight ratio in descending order
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    int currentWeight = 0;
    double totalValue = 0.0;

    // Fill the knapsack with items in a greedy manner
    for (int i = 0; i < numItems; i++) {
        if (currentWeight + items[i].weight <= knapsackCapacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = knapsackCapacity - currentWeight;
            totalValue += (double)items[i].value / items[i].weight * remainingWeight;
            break;
        }
    }

    return totalValue;
}

int main() {
    int numItems;
    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    Item items[numItems];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
    }

    int knapsackCapacity, choice;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &knapsackCapacity);

    printf("Menu:\n");
    printf("1. Solve 0/1 Knapsack problem\n");
    printf("2. Solve Fractional Knapsack problem\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int maxValue = knapsack_01(knapsackCapacity, items, numItems);
            printf("Maximum value achievable: %d\n", maxValue);
            break;
        }
        case 2: {
            double maxValue = fractionalKnapsack(knapsackCapacity, items, numItems);
            printf("Maximum value achievable: %.2lf\n", maxValue);
            break;
        }
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
//n = 3, M = 20, V = (24, 25, 15) and W = (18, 15, 20)
