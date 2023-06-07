#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CITIES 10

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate the total distance of a given tour
int calculateDistance(int tour[], int distanceMatrix[][MAX_CITIES], int numCities) {
    int totalDistance = 0;
    for (int i = 0; i < numCities - 1; i++) {
        int source = tour[i];
        int destination = tour[i + 1];
        totalDistance += distanceMatrix[source][destination];
    }
    // Add the distance from the last city back to the starting city
    totalDistance += distanceMatrix[tour[numCities - 1]][tour[0]];
    return totalDistance;
}

// Function to find the minimal solution using brute force
void tspBruteForce(int distanceMatrix[][MAX_CITIES], int numCities) {
    int tour[MAX_CITIES];
    int minDistance = INT_MAX;
    int *minTour = malloc(numCities * sizeof(int));

    // Generate all possible permutations of cities
    int numPermutations = factorial(numCities - 1);
    for (int i = 1; i < numCities; i++)
        tour[i - 1] = i;

    for (int i = 0; i < numPermutations; i++) {
        int distance = calculateDistance(tour, distanceMatrix, numCities);
        if (distance < minDistance) {
            minDistance = distance;
            for (int j = 0; j < numCities - 1; j++)
                minTour[j] = tour[j];
        }

        // Generate the next permutation
        int j = numCities - 2;
        while (j >= 0 && tour[j] > tour[j + 1])
            j--;

        if (j == -1)
            break;

        int k = numCities - 1;
        while (tour[j] > tour[k])
            k--;

        int temp = tour[j];
        tour[j] = tour[k];
        tour[k] = temp;

        int r = numCities - 1;
        int s = j + 1;
        while (r > s) {
            temp = tour[r];
            tour[r] = tour[s];
            tour[s] = temp;
            r--;
            s++;
        }
    }

    // Print the minimal tour and distance
    printf("Minimal Tour: ");
    for (int i = 0; i < numCities - 1; i++)
        printf("%d -> ", minTour[i]);
    printf("%d\n", minTour[numCities - 2]);
    printf("Minimal Distance: %d\n", minDistance);
}

int main() {
    int distanceMatrix[MAX_CITIES][MAX_CITIES] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int numCities = 4;

    tspBruteForce(distanceMatrix, numCities);

    return 0;
}
