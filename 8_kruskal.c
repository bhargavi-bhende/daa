#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of a vertex (using path compression technique)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two sets (using union by rank)
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges based on their weights (used for sorting)
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to find the Minimum Cost Spanning Tree using Kruskal's algorithm
void kruskalMST(struct Edge* edges, int numEdges, int numVertices) {
    // Allocate memory for subsets
    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));

    // Initialize subsets
    for (int i = 0; i < numVertices; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Sort the edges in non-decreasing order of their weights
    qsort(edges, numEdges, sizeof(struct Edge), compareEdges);

    // Initialize variables
    int mstWeight = 0;  // Minimum Cost Spanning Tree weight
    int mstEdges = 0;   // Number of edges added to the MST

    // Allocate memory for the MST edges
    struct Edge* mst = (struct Edge*)malloc((numVertices - 1) * sizeof(struct Edge));

    // Iterate through all edges in sorted order
    for (int i = 0; i < numEdges; i++) {
        // Get the next edge
        struct Edge currentEdge = edges[i];

        // Find the parent vertices of the current edge
        int x = find(subsets, currentEdge.src);
        int y = find(subsets, currentEdge.dest);

        // If including the current edge doesn't form a cycle, add it to the MST
        if (x != y) {
            mst[mstEdges++] = currentEdge;
            Union(subsets, x, y);
            mstWeight += currentEdge.weight;
        }
    }

    // Print the Minimum Cost Spanning Tree
    printf("Minimum Cost Spanning Tree:\n");
    for (int i = 0; i < mstEdges; i++)
        printf("%d -- %d\tWeight: %d\n", mst[i].src, mst[i].dest, mst[i].weight);
    printf("Total Weight: %d\n", mstWeight);

    // Free allocated memory
    free(subsets);
    free(mst);
}

// Example usage
int main() {
    int numVertices, numEdges;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Create the graph
    struct Edge* edges = (struct Edge*)malloc(numEdges * sizeof(struct Edge));
    printf("Enter the details of each edge (source destination weight):\n");
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Find the Minimum Cost Spanning Tree
    kruskalMST(edges, numEdges, numVertices);

    free(edges);
    return 0;
}
//  {0, 1, 3}, {0, 3, 6}, {0, 2, 1}, {1, 2, 5}, {1, 4, 3}, {2,3,5},{2,4,6},{2,5,4},{3,5,2},{4,5,6} Enter the number of vertices: 6 Enter the number of edges: 10
