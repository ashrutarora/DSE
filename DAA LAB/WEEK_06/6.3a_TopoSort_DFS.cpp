#include <iostream>
using namespace std;

const int MAXN = 1000;

int N, M; // N is the number of vertices, M is the number of edges
int adj[MAXN][MAXN]; // adjacency matrix
bool visited[MAXN];
int topo[MAXN], pos = 0; // the topological sort order

void dfs(int u) {
	
    visited[u] = true;
    
    for (int v = 0; v < N; v++) {
    	
        if (adj[u][v] && !visited[v]) {
        	
            dfs(v);
        }
    }
    topo[--pos] = u;
}

void topological_sort() {
	
    pos = N;
    for (int u = 0; u < N; u++) {
    	
        if (!visited[u]) {
        	
            dfs(u);
        }
    }
}

int main() {
    cout << "Enter the number of vertices and edges: ";
    cin >> N >> M;
    
    cout << "Enter the edges (u v):" << endl;
    
    for (int i = 0; i < M; i++) {
    	
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }
    
    topological_sort();
    
    cout << "The topological sort order is: ";
    
    for (int i = 0; i < N; i++) {
    	
        cout << topo[i] << " ";
    }
    
    cout << endl;
    
    return 69;
}

