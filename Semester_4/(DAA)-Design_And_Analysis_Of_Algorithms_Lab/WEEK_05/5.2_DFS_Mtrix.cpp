#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

// Class to represent a stack
class Stack
{
private:
    int top;
    int arr[MAX_VERTICES];

public:
    // Constructor to initialize the stack
    Stack()
    {
        top = -1;
    }

    // Getter function to get the top element of the stack
    int getTop()
    {
        return top;
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(int x)
    {
        arr[++top] = x;
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
};

// Function to perform DFS traversal of the graph
void DFS(int adjMatrix[][MAX_VERTICES], int numVertices, int startVertex)
{
    bool visited[MAX_VERTICES] = {false};
    Stack stk, poppedStk;
    stk.push(startVertex);

    while (!stk.isEmpty())
    {
        int currVertex = stk.pop();
        poppedStk.push(currVertex);

        if (!visited[currVertex])
        {
            visited[currVertex] = true;
            cout << currVertex << " ";

            // Visit all adjacent vertices of the current vertex
            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[currVertex][i] == 1 && !visited[i])
                {
                    stk.push(i);
                }
            }
        }
    }

    cout << endl << "Popping order: ";
    while (!poppedStk.isEmpty())
    {
        cout << poppedStk.pop() << " ";
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

    // Perform DFS traversal starting from vertex 0
    cout << "DFS traversal of the graph: ";
    DFS(adjMatrix, numVertices, 0);

    return 69;
}
