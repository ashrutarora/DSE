#include <iostream>
using namespace std;

int main()
{
    int n, c;
    cout << "Enter number of items: ";
    cin >> n;

    // Arrays to store the profit and weight of each item
    int p[n+1], wt[n+1];
    cout << "Enter the capacity: ";
    cin >> c;

    // 2D array to store the maximum value that can be obtained with i items and j weight
    int v[n+1][c+1];

    cout << "Enter profit and weight of each item:\n";
    for (int i = 1; i <= n; i++) {
        cout << "Item " << i << ": ";
        cin >> p[i] >> wt[i];
    }

    // Initializing the values for i=0 and w=0
    for (int i = 0; i <= c; i++) {
        v[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        v[i][0] = 0;
    }

    // Dynamic programming loop to calculate the maximum value
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (wt[i] <= j) {
                // If the weight of the current item is less than or equal to the remaining weight, we can choose to include it
                v[i][j] = max(p[i] + v[i-1][j-wt[i]], v[i-1][j]);
            } else {
                // If the weight of the current item is more than the remaining weight, we have no choice but to exclude it
                v[i][j] = v[i-1][j];
            }
        }
    }

    // Printing the items that are included in the knapsack
    int i = n, j = c;
    cout << "The items included are:\n";
    while (i > 0 && j > 0) {
        if (v[i][j] != v[i-1][j]) {
            cout << i << " ";
            j -= wt[i];
        }
        i--;
    }
    cout << endl;

    int maxVal = v[n][c];
    cout << "The maximum value is: " << maxVal << endl;

    return 0;
}
