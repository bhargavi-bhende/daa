#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to perform Depth-First Search traversal
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int current_vertex, int num_vertices) {
    printf("%d ", current_vertex); // Print the current vertex
    visited[current_vertex] = 1; // Mark the current vertex as visited

    // Visit all the adjacent vertices
    for (int i = 0; i < num_vertices; i++) {
        if (graph[current_vertex][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, i, num_vertices);
        }
    }
}

// Function to perform Breadth-First Search traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int start_vertex, int num_vertices) {
    int queue[MAX_VERTICES]; // Queue for BFS traversal
    int front = 0, rear = 0;

    visited[start_vertex] = 1; // Mark the start vertex as visited
    printf("%d ", start_vertex); // Print the start vertex
    queue[rear++] = start_vertex; // Enqueue the start vertex

    // Perform BFS traversal
    while (front < rear) {
        int current_vertex = queue[front++]; // Dequeue a vertex

        // Visit all the adjacent vertices
        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1; // Mark the vertex as visited
                printf("%d ", i); // Print the vertex
                queue[rear++] = i; // Enqueue the vertex
            }
        }
    }
}

// Function to check if a graph is connected using DFS
bool isConnectedDFS(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    int visited[MAX_VERTICES] = {0}; // Initialize all vertices as not visited

    // Start DFS from the first vertex
    DFS(graph, visited, 0, num_vertices);

    // Check if all vertices are visited
    for (int i = 0; i < num_vertices; i++) {
        if (visited[i] == 0) {
            return false; // Graph is not connected
        }
    }

    return true; // Graph is connected
}

// Function to check if a graph is connected using BFS
bool isConnectedBFS(int graph[MAX_VERTICES][MAX_VERTICES], int num_vertices) {
    int visited[MAX_VERTICES] = {0}; // Initialize all vertices as not visited
    int queue[MAX_VERTICES]; // Queue for BFS traversal
    int front = 0, rear = 0;

    visited[0] = 1; // Mark the first vertex as visited
    queue[rear++] = 0; // Enqueue the first vertex

    // Perform BFS traversal
    while (front < rear) {
        int current_vertex = queue[front++]; // Dequeue a vertex

        // Visit all the adjacent vertices
        for (int i = 0; i < num_vertices; i++) {
            if (graph[current_vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1; // Mark the vertex as visited
                printf("%d ", i); // Print the vertex
                queue[rear++] = i; // Enqueue the vertex
            }
        }
    }

    // Check if all vertices are visited
    for (int i = 0; i < num_vertices; i++) {
        if (visited[i] == 0) {
            return false; // Graph is not connected
        }
    }

    return true; // Graph is connected
}

int main() {
    int num_vertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    bool connectedDFS = isConnectedDFS(graph, num_vertices);
    bool connectedBFS = isConnectedBFS(graph, num_vertices);

    if (connectedDFS) {
        printf("Graph is connected (DFS).\nDFS Traversal: ");
        int visited[MAX_VERTICES] = {0}; // Initialize visited array
        DFS(graph, visited, 0, num_vertices);
        printf("\n");
    } else {
        printf("Graph is not connected (DFS).\n");
    }

    if (connectedBFS) {
        printf("Graph is connected (BFS).\nBFS Traversal: ");
        int visited[MAX_VERTICES] = {0}; // Initialize visited array
        BFS(graph, visited, 0, num_vertices);
        printf("\n");
    } else {
        printf("Graph is not connected (BFS).\n");
    }

    return 0;
}
