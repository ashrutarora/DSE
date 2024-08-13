// Implement Traveling Salesman Problem using Exhaustive Search 


#include <iostream>
#include <climits>

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
    if (currVertex == n) {
        int weight = computePathWeight(graph, path, n);
        if (weight < minWeight) {
            minWeight = weight;
            minPath = path[0];
            for (int i = 1; i < n; i++) {
                minPath = minPath * 10 + path[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path[currVertex] = i;
            tsp(graph, path, visited, currVertex+1, n, minWeight, minPath);
            visited[i] = false;
        }
    }
}

int main() {
    int n, graph[MAX_VERTICES][MAX_VERTICES];

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int path[MAX_VERTICES], minPath = 0, minWeight = INT_MAX;
    bool visited[MAX_VERTICES] = { false };
    visited[0] = true;
    path[0] = 0;

    tsp(graph, path, visited, 1, n, minWeight, minPath);

    cout << "Shortest path: " << minPath << endl;
    cout << "Path weight: " << minWeight << endl;

    return 69;
}
