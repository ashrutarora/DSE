#include <iostream>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V)
{
    int minKey = INT_MAX, minIndex;

    for (int i = 0; i < V; i++) {
        if (mstSet[i] == false && key[i] < minKey) {

            minKey = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to print the minimum spanning tree
void printMST(int parent[], int graph[][100], int V)
{
    int y = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        y += graph[i][parent[i]];
    }
     cout << "Min cost of Spanning Tree = " << y;
    
}

// Function to perform Prim's algorithm
void prim(int graph[][100], int V)
{
    int parent[V]; // Array to store constructed minimum spanning tree
    int key[V]; // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < V; i++) {
        
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // Construct MST for all vertices
    for (int count = 0; count < V-1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the minimum spanning tree
    printMST(parent, graph, V);
}

int main()
{
    int V;

    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100]; // 2D array to store the graph

    // Get input for the graph
    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Run Prim's algorithm
    prim(graph, V);

    return 0;
}