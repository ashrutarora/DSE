
// Write a program for assignment problem by brute-force technique. 



#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_SIZE = 100;

// Function to find the minimum cost of assignment
int assignment_brute_force(int costMatrix[][MAX_SIZE], int n, int assignment[]) {
    int minCost = INT_MAX;
    int agents[n];
    for (int i = 0; i < n; i++) {
        agents[i] = i;
    }

    // Generate all possible permutations of agents
    do {
        int currCost = 0;
        // Calculate the cost for the current permutation
        for (int i = 0; i < n; i++) {
            currCost += costMatrix[i][agents[i]];
        }
        // Update minimum cost if current cost is lower
        if (currCost < minCost) {
            minCost = currCost;
            for (int i = 0; i < n; i++) {
                assignment[i] = agents[i];
            }
        }
    } while (next_permutation(agents, agents + n));

    return minCost;
}

// Driver code with input from user
int main() {
    int n;
    cout << "Enter the number of agents and tasks (maximum size " << MAX_SIZE << "): ";
    cin >> n;
    int costMatrix[MAX_SIZE][MAX_SIZE];
    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> costMatrix[i][j];
        }
    }
    int assignment[n];
    int minCost = assignment_brute_force(costMatrix, n, assignment);
    cout << "Minimum cost of assignment: " << minCost << endl;
    cout << "Assignments:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Agent " << i+1 << " takes task " << assignment[i]+1 << endl;
    }
    return 0;
}
