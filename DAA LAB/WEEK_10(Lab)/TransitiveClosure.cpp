#include <iostream>

using namespace std;

const int MAXN = 100;

// This function computes the transitive closure of a given directed graph using Warshall's algorithm
void warshall(int n, int adj[][MAXN], int closure[][MAXN]) {
    // Initialize the closure matrix to be the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            closure[i][j] = adj[i][j];
        }
    }

    // Apply the Warshall's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);
                // The (i, j) element of the closure matrix is set to 1 if there exists a path from i to j
                // that goes through k. This is done by checking if there is a path from i to k and a path
                // from k to j in the closure matrix, and taking their logical OR.
            }
        }
    }
}

int main() {
    int n;
    int adj[MAXN][MAXN];
    int closure[MAXN][MAXN];

    // Read the input graph
    cout << "Enter the dimension of the graph: ";

    cin >> n;

    cout << "Enter the adjacency matrix : " << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    cout << endl;

    // Compute the transitive closure
    warshall(n, adj, closure);


    // Print the transitive closure

    cout << "Transitive Closure: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << closure[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
