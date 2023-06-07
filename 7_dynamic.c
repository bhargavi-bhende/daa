#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the Knapsack problem using Dynamic Programming
int knapsack(int capacity, int weights[], int values[], int n) {
    // Create a table to store the maximum values for each subproblem
    int table[n + 1][capacity + 1];

    // Initialize the table with zeros
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (weights[i - 1] <= j)
                table[i][j] = max(values[i - 1] + table[i - 1][j - weights[i - 1]], table[i - 1][j]);
            else
                table[i][j] = table[i - 1][j];
        }
    }

    // Return the maximum value that can be achieved
    return table[n][capacity];
}

// Main function
int main() {
    int capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n];
    int values[n];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be obtained is: %d\n", maxValue);

    return 0;
}
//val[] = {60, 100, 120}; int wt[] = {10, 20, 30}; W = 50;
