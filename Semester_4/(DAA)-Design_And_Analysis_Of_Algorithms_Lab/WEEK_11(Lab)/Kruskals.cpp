#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

// class to represent an edge in the graph
class Edge {
public:
    int src, dest, weight;
};

// class to represent a graph with V vertices and E edges
class Graph {
public:
    int V, E;
    Edge* edge;

    // constructor to create a graph with V vertices and E edges
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        edge = new Edge[E];
    }

    // function to find the subset of an element i
    int find(int parent[], int i)
    {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    // function to perform union of two subsets
    void Union(int parent[], int x, int y)
    {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    // function to perform Kruskal's algorithm to find Minimum Spanning Tree of a graph
    void KruskalMST()
    {
        Edge result[V]; // This will store the resultant Minimum Spanning Tree (MST)
        int e = 0; // counter for edges in result
        int i = 0; // counter for edges in graph

        // sort all edges in non-decreasing order of their weight
        for (i = 0; i < E; i++) {
            for (int j = i + 1; j < E; j++) {
                if (edge[i].weight > edge[j].weight) {
                    swap(edge[i], edge[j]);
                }
            }
        }

        // allocate memory for creating V subsets
        int *parent = new int[V];

        // initialize all subsets as single element sets
        memset(parent, -1, sizeof(int) * V);

        i = 0;

        // process all E edges in the sorted order
        while (e < V - 1 && i < E) {
            // pick the smallest edge and increment the index for next iteration
            Edge next_edge = edge[i++];

            // find the subsets of the vertices of the next edge
            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            // if including this edge does not cause a cycle, include it in the result and increment the index for the next edge
            if (x != y) {
                result[e++] = next_edge;
                Union(parent, x, y);
            }
        }

        // print the contents of result[] to display the built MST
        cout << "Following are the edges in the constructed MST:" << endl;
        int minimumCost = 0;
        for (i = 0; i < e; i++) {
            cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
            minimumCost += result[i].weight;
        }
        cout << "Total cost of the MST: " << minimumCost << endl;

        return;
    }
};

int main()
{
    int V, E;

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V, E); // create a graph with V vertices and E edges

    // get input for the graph
    for (int i = 0; i < E; i++) {
    int u, v, w;
    cout << "Enter the details of edge " << i + 1 << " (src dest weight): ";
    cin >> u >> v >> w;
    graph.edge[i].src = u;
    graph.edge[i].dest = v;
    graph.edge[i].weight = w;
    }
    // perform Kruskal's algorithm to find Minimum Spanning Tree of the graph
    graph.KruskalMST();

    return 0;
}
