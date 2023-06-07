#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Data structure to represent a graph
struct Graph {
    int numVertices;
    int** adjacencyMatrix;
};

// Utility function to create a new graph
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->adjacencyMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(numVertices, sizeof(int));
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
}

// Depth First Search (DFS) recursive function
int isCyclicDFS(struct Graph* graph, int vertex, int* visited, int* stack) {
    visited[vertex] = 1;
    stack[vertex] = 1;

    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] == 1) {
            if (!visited[i] && isCyclicDFS(graph, i, visited, stack))
                return 1;
            else if (stack[i])
                return 1;
        }
    }

    stack[vertex] = 0;
    return 0;
}

// Function to check if the graph contains a cycle
int isCyclic(struct Graph* graph) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* stack = (int*)calloc(graph->numVertices, sizeof(int));

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i] && isCyclicDFS(graph, i, visited, stack))
            return 1;
    }

    return 0;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    if (isCyclic(graph))
        printf("The graph contains a cycle.\n");
    else
        printf("The graph does not contain a cycle.\n");

    return 0;
}
/* Enter the number of vertices in the graph: 4
Enter the number of edges in the graph: 5
Enter the edges (source destination):
0 1
0 2
1 2
2 0
2 3 */
