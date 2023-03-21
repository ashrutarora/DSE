#include <iostream>
using namespace std;

const int MAXN = 1000;

bool adj[MAXN][MAXN];
int indeg[MAXN];

void topological_sort(int N) {
	
    int remaining = N;
    
    while (remaining > 0) {
    	
        // Find a vertex with no incoming edges (indegree = 0)
        int u = -1;
        
        for (int i = 0; i < N; i++) {
        	
            if (indeg[i] == 0) {
            	
                u = i;
                break;
            }
        }
        
        if (u == -1) {
        	
            // There is a cycle in the graph, so we can't do a topological sort
            cout << "Error: the graph contains a cycle\n";
            return;
        }
        
        // Output u and remove all outgoing edges from u
        cout << u << " ";
        
        for (int v = 0; v < N; v++) {
        	
            if (adj[u][v]) {
            	
                indeg[v]--;
            }
        }
        remaining--;
    }
    cout << endl;
}

int main() {
	
    int N, M;
    
    cout << "Enter the number of vertices: ";
    cin >> N;
    
    cout << "Enter the number of edges: ";
    cin >> M;
    
    cout << "Enter the edges (u v):" << endl;
    
    for (int i = 0; i < M; i++) {
    	
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
        indeg[v]++;
    }
    
    topological_sort(N);
    
    return 69;
}

