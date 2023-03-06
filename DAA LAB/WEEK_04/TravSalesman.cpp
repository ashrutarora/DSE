#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_VERTICES = 10;

// Function to compute the total weight of a given path
int computePathWeight(int graph[][MAX_VERTICES], int path[], int n) {
    int weight = 0;
    for (int i = 0; i < n-1; i++) {
        weight += graph[path[i]][path[i+1]];
    }
    weight += graph[path[n-1]][path[0]]; // Add weight of returning to the starting vertex
    return weight;
}

// Function to compute the shortest path using brute force
void tsp(int graph[][MAX_VERTICES], int path[], bool visited[], int currVertex, int n, int& minWeight, int& minPath) {
    if (currVertex == n) { // If all vertices have been visited
        int weight = computePathWeight(graph, path, n); // Compute the weight of the path
        if (weight < minWeight) { // If the weight is less than the current minimum weight
            minWeight = weight; // Update the minimum weight
            minPath = path[0]; // Initialize the minimum path
            for (int i = 1; i < n; i++) { // Construct the minimum path
                minPath = minPath * 10 + path[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) { // Visit all unvisited vertices
        if (!visited[i]) {
            visited[i] = true;
            path[currVertex] = i; // Add the vertex to the current path
            tsp(graph, path, visited, currVertex+1, n, minWeight, minPath); // Recursively visit the next vertex
            visited[i] = false; // Backtrack
        }
    }
}

int main() {
    int n, graph[MAX_VERTICES][MAX_VERTICES];

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < n; i++) { // Input the adjacency matrix of the graph
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int path[MAX_VERTICES], minPath = 0, minWeight = INT_MAX; // Initialize the path, minimum path and minimum weight
    bool visited[MAX_VERTICES] = { false }; // Initialize the visited array
    visited[0] = true; // Mark the starting vertex as visited
    path[0] = 0; // Add the starting vertex to the path

    tsp(graph, path, visited, 1, n, minWeight, minPath); // Find the shortest path

    cout << "Shortest path: " << minPath << endl; // Output the shortest path
    cout << "Path weight: " << minWeight << endl; // Output the weight of the shortest path

    return 0; // End the program
}

