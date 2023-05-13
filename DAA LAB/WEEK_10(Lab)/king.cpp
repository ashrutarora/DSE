#include <iostream>
using namespace std;

const int MAX = 100;

void warshall(int adj[MAX][MAX], int closure[MAX][MAX], int v){

    // Copy the adjacency matrix to the closure matrix
    for(int i = 0; i < v ; i++){
        for(int j = 0; j < v; j++){
            closure[i][j] = adj[i][j];
        }
    }

    // Apply Warshall's algorithm to the closure matrix
    for(int k = 0; k < v; k++){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(closure[i][j] == 0 && closure[i][k] == 1 && closure[k][j] == 1){
                    closure[i][j] = 1;
                }
            }
        }
    }

    // Print the closure matrix
    for(int i = 0; i < v ; i++){
        for(int j = 0; j < v; j++){
            cout << closure[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int v, e;

    int adj[MAX][MAX];
    int closure[MAX][MAX];

    cout << "Enter the number of Vertices: ";
    cin >> v;

    cout << "Enter the number of Edges: ";
    cin >> e;

    memset(adj, 0 , sizeof(adj));

    for(int i = 0; i < e; i++){
        int u, v;
        cout << "Enter the Source and Destination: ";
        cin >> u >> v;
        adj[u][v] = 1;
    }

    warshall(adj, closure, v);

    return 0;
}
