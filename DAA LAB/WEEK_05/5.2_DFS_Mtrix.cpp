#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

// Structure to represent a stack
struct Stack {
    int top;
    int arr[MAX_VERTICES];
};

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack* s, int x) {
    s->arr[++s->top] = x;
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        cout << "Stack underflow!" << endl;
        return -1;
    }
    return s->arr[s->top--];
}

// Function to perform DFS traversal of the graph
void DFS(int adjMatrix[][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    Stack stk;
    initStack(&stk);
    push(&stk, startVertex);

    while (!isEmpty(&stk)) {
        int currVertex = pop(&stk);

        if (!visited[currVertex]) {
            visited[currVertex] = true;
            cout << currVertex << " ";

            // Visit all adjacent vertices of the current vertex
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currVertex][i] == 1 && !visited[i]) {
                    push(&stk, i);
                }
            }
        }
    }
}

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

    return 69;
}

