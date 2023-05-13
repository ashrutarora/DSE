#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){

    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){

        largest = left;
    }

     if(right  < n && arr[right] > arr[largest]){

        largest = right;
    }

    if(largest != i){

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    } 
}

void heapSort(int arr[], int n){

    for(int i = (n/2)-1; i >= 0; i--){

        heapify(arr, n, i);
    }

    for(int i = n-1; i  >= 0; i--){

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void deleteRoot(int arr[], int &n){

    if(n == 0)
        return;

    arr[0] = arr[n-1];
    n--;

    heapify(arr, n, 0);
}


int main(){

    int n;

    cout << "Enter number of elements in the array : ";
    cin >> n;

    int arr[n];

    // Input
    for(int i = 0; i < n; i++){

        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];
    }

    heapSort(arr, n);

    // Output
    for(int i = 0; i < n; i++){

        cout << arr[i] << " ";
    }

    cout << endl;

    deleteRoot(arr, n);

    for(int i = 0; i < n; i++){

        cout << arr[i] << " ";
    }

    return 0;
}