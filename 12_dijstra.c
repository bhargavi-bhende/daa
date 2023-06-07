#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 10

int findNearestNeighbor(int city, bool visited[], int distances[][MAX_CITIES], int numCities) {
    int nearestNeighbor = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < numCities; i++) {
        if (!visited[i] && distances[city][i] < minDistance) {
            minDistance = distances[city][i];
            nearestNeighbor = i;
        }
    }

    return nearestNeighbor;
}

void tspNearestNeighbor(int startCity, int distances[][MAX_CITIES], int numCities) {
    bool visited[MAX_CITIES] = {false};

    visited[startCity] = true;
    int currentCity = startCity;
    int path[MAX_CITIES];
    int pathIndex = 0;
    int totalDistance = 0;

    path[pathIndex++] = currentCity;

    for (int i = 0; i < numCities - 1; i++) {
        int nearestNeighbor = findNearestNeighbor(currentCity, visited, distances, numCities);
        visited[nearestNeighbor] = true;
        path[pathIndex++] = nearestNeighbor;
        totalDistance += distances[currentCity][nearestNeighbor];
        currentCity = nearestNeighbor;
    }

    totalDistance += distances[currentCity][startCity];

    printf("Optimal path: ");
    for (int i = 0; i <= pathIndex; i++) {
        printf("%d ", path[i]);
    }

    printf("\nMinimum path length: %d\n", totalDistance);
}

int main() {
    int numCities;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    int distances[MAX_CITIES][MAX_CITIES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &distances[i][j]);
        }
    }

    int startCity;
    printf("Enter the starting city index (0 to %d): ", numCities - 1);
    scanf("%d", &startCity);

    tspNearestNeighbor(startCity, distances, numCities);

    return 0;
}
/*Enter the number of cities: 5
Enter the adjacency matrix:
0 2 9 10 15
2 0 6 4 11
9 6 0 3 7
10 4 3 0 8
15 11 7 8 0
Enter the starting city index (0 to 4): 0
Optimal path: 0 1 3 2 4 0
Minimum path length: 31 *1/
