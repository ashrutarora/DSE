#include <iostream>
using namespace std;

const int MAX_VERTICES = 100;

// Structure to represent a queue
struct Queue {
    int front, rear;
    int arr[MAX_VERTICES];
};

// Function to initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to check if the queue is full
bool isFull(Queue* q) {
    return (q->rear + 1) % MAX_VERTICES == q->front;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int x) {
    if (isFull(q)) {
        cout << "Queue overflow!" << endl;
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % MAX_VERTICES;
    }
    q->arr[q->rear] = x;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        cout << "Queue underflow!" << endl;
        return -1;
    }
    int x = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % MAX_VERTICES;
    }
    return x;
}

// Function to perform BFS traversal of the graph
void BFS(int adjMatrix[][MAX_VERTICES], int numVertices, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    Queue q;
    initQueue(&q);
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currVertex = dequeue(&q);

        if (!visited[currVertex]) {
            visited[currVertex] = true;
            cout << currVertex << " ";

            // Visit all adjacent vertices of the current vertex
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[currVertex][i] == 1 && !visited[i]) {
                    enqueue(&q, i);
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

    // Perform BFS traversal starting from vertex 0
    cout << "BFS traversal of the graph: ";
    BFS(adjMatrix, numVertices, 0);
    cout << endl;

    return 69;
}

