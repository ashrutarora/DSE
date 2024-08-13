/*
Write a program to implement Knapsack problem using brute-force design
technique and analyze its time efficiency.
Knapsack Problem: Given n items of known weights w1, w2 ... wn values v1, v2, ...
vn and a knapsack of capacity B, find the most valuable subset of items that fit into
the knapsack.
*/

#include <iostream>
#include <cmath>
using namespace std;

// This function calculates the optimal Knapsack sequence
// given the weights, values, number of items, and capacity
// of the Knapsack.
unsigned int Knapsack(unsigned int *w, unsigned int *v, unsigned int n, unsigned int B)
{
    unsigned int i, temp;
    unsigned int maxVal = 0, maxSequence = 0;
    unsigned int totalWeight, totalValue;
    unsigned int index = 0;

    // Generate bit array
    for (i = 1; i < pow(2, n); i++)
    {
        // Compute total weight and value
        temp = i;
        totalWeight = totalValue = 0;
        index = 0;
        while (temp)
        {
            if (temp & 0x1)
            {
                totalWeight += w[index];
                totalValue += v[index];
            }
            index++;
            temp >>= 1;
        }

        // Update the maximum value and sequence if the current
        // sequence has a lower total weight than the Knapsack
        // capacity and a higher total value than the current maximum.
        if (totalWeight <= B && totalValue > maxVal)
        {
            maxVal = totalValue;
            maxSequence = i;
        }
    }

    return maxSequence;
}

int main()
{
    unsigned int n, B;
    cout << "Enter the number of items: ";
    cin >> n;

    // Allocate memory for the weight and value arrays
    unsigned int *w = new unsigned int[n];
    unsigned int *v = new unsigned int[n];

    cout << "Please enter the Weights and Values of the " << n << " items, separated by a space:\n";

    // Read in the weight and value of each item
    for (unsigned int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }

    cout << "Please enter the capacity of the Knapsack: ";
    cin >> B;

    // Compute the optimal Knapsack sequence
    unsigned int knaps = Knapsack(w, v, n, B);

    cout << "Knapsack contains the following Items:\n";

    // Print out the items in the Knapsack
    unsigned int i = 0;
    while (knaps)
    {
        if (knaps & 0X1)
        {
            cout << "Item " << (i + 1) << " Value " << v[i] << endl;
        }
        i++;
        knaps >>= 1;
    }

    // Free the memory used by the weight and value arrays
    delete[] w;
    delete[] v;

    return 0;
}
