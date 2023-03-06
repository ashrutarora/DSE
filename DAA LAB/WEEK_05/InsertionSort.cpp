#include <iostream>
using namespace std;

// We use &a and &b so as to PASS BY REF, which thefo swaps the values in array.
void swapNum(int &a, int &b){

    int temp = a;
    a = b;
    b = temp;
}

void InsSort(int arr[], int size){
	
    for(int i = 0; i < size; i++){
    	
    	int v = arr[i];
    	int j = i - 1;
    	
    	while(j >= 0 && arr[j] > v){
    		
    		arr[j+1] = arr[j];
    		j--;
		}
		arr[j+1] = v;
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

    InsSort(arr, size);

    cout << "Sorted Array using INSERTION SORT: " << endl;

    for(int i =0; i < size; i++){

        cout << arr[i] << " ";
    }

    return 69;
}
