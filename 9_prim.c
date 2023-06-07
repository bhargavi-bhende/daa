#include <stdio.h>
#include <stdbool.h>
#define INF 999999

// Number of vertices in the graph
int V;

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[])
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the minimum cost spanning tree
void printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to construct and print the minimum cost spanning tree
void primMST(int graph[V][V])
{
    int parent[V];  // Array to store constructed MST
    int key[V];     // Key values used to pick the minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the vertex with the minimum key value from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key values and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
        {
            // Update the key only if the graph[u][v] is smaller than the current key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Function call to find the minimum cost spanning tree
    primMST(graph);

    return 0;
}
/* 0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0 */
