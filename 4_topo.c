#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the graph
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Node* adj[], int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

// Depth-First Search (DFS) traversal
void dfs(int v, struct Node* adj[], int visited[], int* stack, int* top) {
    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfs(adjVertex, adj, visited, stack, top);
        }
        temp = temp->next;
    }

    stack[++(*top)] = v;
}

// Topological Sort using DFS
void topologicalSortDFS(int V, struct Node* adj[]) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int top = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v]) {
            dfs(v, adj, visited, stack, &top);
        }
    }

    printf("Topological Ordering (DFS): ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

// Topological Sort using BFS
void topologicalSortBFS(int V, struct Node* adj[]) {
    int inDegree[MAX_VERTICES] = {0};

    // Calculate in-degree for each vertex
    for (int v = 0; v < V; v++) {
        struct Node* temp = adj[v];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            inDegree[adjVertex]++;
            temp = temp->next;
        }
    }

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    // Enqueue all vertices with in-degree 0
    for (int v = 0; v < V; v++) {
        if (inDegree[v] == 0) {
            queue[++rear] = v;
        }
    }

    printf("Topological Ordering (BFS): ");
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            inDegree[adjVertex]--;

            if (inDegree[adjVertex] == 0) {
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Driver function
int main() {
    int V = 6; // Number of vertices

    // Array of adjacency lists to represent the graph
    struct Node* adj[MAX_VERTICES] = {NULL};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    topologicalSortDFS(V, adj);
    topologicalSortBFS(V, adj);

    return 0;
}
