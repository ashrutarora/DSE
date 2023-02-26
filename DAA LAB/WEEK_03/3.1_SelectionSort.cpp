// Write a program to sort a set of integers using selection sort algorithm and analyze its time efficiency.

#include <iostream>
using namespace std;

// We use &a and &b so as to PASS BY REF, which thefo swaps the values in array.
void swapNum(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;
}

// We initialize the first element as min
// Then we check for the actual minimum element in the array and then swap them and increment min, which here is done by i.

void SelecSort(int arr[], int size){

    //This loop is run till size-1 as by the last pass, the largest element comes to the end and we need not run the loop for 1 more time.
    for(int i = 0; i < size-1; i++){

        int min = i;
        // This loop starts from i+1 as we have to compare the elements after the selected element.
        for(int j = i+1; j < size; j++){

            if(arr[j] < arr[min]){

                min = j;
            }
        }
        swapNum(arr[i], arr[min]);
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

    SelecSort(arr, size);

    cout << "Sorted Array using INSERTION SORT" << endl;

    for(int i =0; i < size; i++){

        cout << arr[i] << " ";
    }

    return 69;
}
