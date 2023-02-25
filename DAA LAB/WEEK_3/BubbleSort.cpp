#include <iostream>
using namespace std;

// We use &a and &b so as to PASS BY REF, which thefo swaps the values in array.
void swapNum(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;
}

// We check the adjacent elements and then if the adj element is lesser, then we swap it
// We swap it until the largest element comes to the end of the array.
void BubbleSort(int arr[], int size){

    for(int i = 0; i < size-1; i++){

        for(int j = 0; j < size-i-1 ; j++){

            if(arr[j] > arr[j+1]){

                swapNum(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){

    int size;

    cout << "Enter the number of Elements in the array : " << endl;
    cin >> size;

    int arr[size];

    for(int i =0; i < size; i++){

        cout << "Enter arr[" << i <<  "] : ";
        cin >> arr[i];
    }

    BubbleSort(arr, size);

    cout << "Sorted Array using BUBBLE SORT" << endl;
    
    for(int i =0; i < size; i++){

        cout << arr[i] << " ";
    }

    return 69;
}