#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

// Class to represent a queue
class Queue
{
private:
    int front, rear;
    int arr[MAX_VERTICES];

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (rear + 1) % MAX_VERTICES == front;
    }

    // Function to add an element to the rear of the queue
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue overflow!" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_VERTICES;
        }
        arr[rear] = x;
    }

    // Function to remove an element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_VERTICES;
        }
        return x;
    }
};

// Function to perform BFS traversal of the graph
void BFS(int adjMatrix[][MAX_VERTICES], int numVertices, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    int poppedOrder[MAX_VERTICES], numPopped = 0;
    Queue q;
    q.enqueue(startVertex);

    while (!q.isEmpty())
    {
        int currVertex = q.dequeue();
        poppedOrder[numPopped++] = currVertex;

        if (!visited[currVertex])
        {
            visited[currVertex] = true;
            cout << currVertex << " ";

            // Visit all adjacent vertices of the current vertex
            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currVertex][i] == 1 && !visited[i])
                {
                    q.enqueue(i);
                }
            }
        }
    }

    cout << "\nPopped order: ";
    for (int i = 0; i < numPopped; i++)
    {
        cout << poppedOrder[i] << " ";
    }
}



int main()
{
    int numVertices, numEdges;

    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    // Create adjacency matrix for the graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    cout << "Enter the edges: " << endl;

    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = adjMatrix[v][u] = 1;
    }

    // Perform BFS traversal starting from vertex 0
    cout << "BFS traversal of the graph: ";
    BFS(adjMatrix, numVertices, 0);
    cout << endl;

    return 69;
}
