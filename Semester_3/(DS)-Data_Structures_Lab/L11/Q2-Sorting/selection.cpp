#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swap(int arr[] , int pos1, int pos2){
	int temp;
	temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_in;
    for (i = 0; i < n; i++)
    {
        min_in = i;

        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_in])
                min_in = j;
                
        swap(arr, i, min_in);
    }
}
int main(int argv, char *argc[])
{

    cout << "Enter the size of array : " << endl;
    int ele;
	cin>>ele;

    int arr[ele];

    cout << "Enter the elements of Array: " << endl;
	for( int i = 0 ; i < ele; i++){
		cin>> arr[i];
	}

    cout << "Unsorted Array :";
    print(arr, ele);

    selectionSort(arr, ele);

    cout << "Sorted Array :";
    print(arr, ele);

    return (0);
}