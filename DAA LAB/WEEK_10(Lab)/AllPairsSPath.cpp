#include <iostream>

#define INF 1000000000 // Define a constant to represent infinity

using namespace std;

int main() {
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    int adjMatrix[n][n];
    cout << "Enter the adjacency matrix for the graph:\n";
    // Read in the adjacency matrix from the user
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            // If the user enters -1, set the edge weight to infinity
            if (x == -1) {
                adjMatrix[i][j] = INF;
            } else {
                adjMatrix[i][j] = x;
            }
        }
    }

    // Compute the shortest paths between all pairs of vertices using dynamic programming
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If the path from i to j through k is shorter than the current shortest path from i to j, update the shortest path
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }

    // Print the shortest paths between all pairs of vertices
    cout << "The shortest distances between all pairs of vertices are:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If the shortest path is infinity, print INF, otherwise print the shortest path
            if (adjMatrix[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << adjMatrix[i][j] << "\t";
            }
        }
        cout << endl;
    }

    return 0;
}
