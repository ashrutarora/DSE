#include<iostream>
#include<climits>
using namespace std;

const int MAX=100;
int numVertices,numEdges;
int adjMatrix[MAX][MAX];

int miniDist(int distance[], bool Tset[])
{
    int minimum=INT_MAX,ind;

    for(int k=0;k<numVertices;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[MAX][MAX],int src)
{
    // The output array. dist[i] will hold the shortest distance from the source vertex to vertex i
    int distance[numVertices]; 

    // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized
    bool Tset[numVertices];

    // Initialize all distances as INFINITE and sptSet[] as false
    for(int k = 0; k<numVertices; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    // Distance of source vertex from itself is always 0
    distance[src] = 0;
    //Tset[src] = true;

    // Find shortest path for all vertices
    for(int i = 0; i<numVertices; i++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // m is always equal to src in first iteration.
        int m = miniDist(distance,Tset);

        // Mark the picked vertex as processed
        Tset[m]=true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for(int j = 0; j<numVertices; j++)
        {

            // If Tset[j] has not been processed yet
            // If there exists an edge between M and J
            // If the distance[j] from Source != INFINITY
            // If distance[m] + graph[m][j] < distance[j]
            
            if(Tset[j] == false && graph[m][j] && distance[m]!=INT_MAX && distance[m]+graph[m][j]<distance[j])
                distance[j]=distance[m]+graph[m][j];
        }
    }

    // Print the final distances from the source vertex

    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<numVertices; k++)
    {
        
        cout<<k<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{       
    cout<<"Enter the no of vertices"<<endl;
    cin >> numVertices;

    cout<<"Enter no of edges"<<endl;
    cin>> numEdges;

    memset(adjMatrix, 0, sizeof(adjMatrix));

    for (int i = 0; i < numEdges; i++) {

        int u, v, w;

        cout<<"Enter source and destination and weight of the edge"<<endl;

        cin >> u >> v >> w;
        
        // Add edge to adjacency matrix
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;

    }
        cout<<"enter a source vertex for traversing :";
        int src;
        cin>>src;

    DijkstraAlgo(adjMatrix,src);
    
    return 0;
}