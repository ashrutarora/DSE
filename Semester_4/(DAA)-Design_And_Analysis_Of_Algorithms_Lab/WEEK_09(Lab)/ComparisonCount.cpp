#include <iostream>
using namespace std;

// Comparison counting sort function
void comparisonCountingSort(int arr[], int n) {
    // Find the maximum value in the array
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {

        if (arr[i] > max_val) {

            max_val = arr[i];
        }
    }

    // Create a count array and initialize all its elements to 0
    int count[max_val+1];

    memset(count, 0, sizeof(count));
    
    // Loop over the input array and increment the count for each value we encounter
    for (int i = 0; i < n; i++) {

        count[arr[i]]++;
        
    }

    // Modify the count array so that each element contains the number of elements that are less than or equal to it
    for (int i = 1; i <= max_val; i++) {

        count[i] += count[i-1];
    }

    // Create a new array to hold the sorted output
    int sorted_arr[n];

    // Loop over the input array again and place each element in the sorted array at its appropriate position based on the count array
    for (int i = 0; i < n; i++) {

        sorted_arr[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array back into the input array
    for (int i = 0; i < n; i++) {

        arr[i] = sorted_arr[i];
    }
}

int main() {
    // Get the size of the input array from the user
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Create an array of the specified size and fill it with values from the user
    int arr[n];
    for (int i = 0; i < n; i++) {

        cout << "Enter element " << i+1 << ": ";
        cin >> arr[i];
    }

    // Sort the array using comparison counting sort
    comparisonCountingSort(arr, n);

    cout << endl;

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
