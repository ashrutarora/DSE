/*
Write a program for depth-first search of a graph. Identify the push and pop order of vertices. 
*/

#include <iostream>
#include <stack>
using namespace std;

const int MAX_VERTICES = 100;

// Function to perform DFS traversal of the graph
void DFS(int adjMatrix[][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    stack<int> stk;
    stk.push(startVertex);

    while (!stk.empty()) {
        int currVertex = stk.top();
        stk.pop();

        if (!visited[currVertex]) {
            visited[currVertex] = true;
            cout << currVertex << " ";

            // Visit all adjacent vertices of the current vertex
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currVertex][i] == 1 && !visited[i]) {
                    stk.push(i);
                }
            }
        }
    }
}

// Driver code to test the DFS function
int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    // Create adjacency matrix for the graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = { 0 };
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    // Perform DFS traversal starting from vertex 0
    cout << "DFS traversal of the graph: ";
    DFS(adjMatrix, numVertices, 0);
    cout << endl;

    return 0;
}
