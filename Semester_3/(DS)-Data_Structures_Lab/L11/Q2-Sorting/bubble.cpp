#include <iostream>
using namespace std;

void BubbleSort(int a[], int ele){

    for (int i = 0; i < ele; i++)
    {
        for (int j = i + 1; j < ele; j++)
        {
            if (a[j] < a[i])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Sorted Element List ..." << endl;

    for (int i = 0; i < ele; i++)
    {
        cout << a[i] << "\t";
    }
}

int main(){

    int i, j, temp, pass = 0, ele;

    cout << "Enter the number of elements in Array" << endl;
    cin >> ele;

    int a[ele];

    cout << "Enter the elements : " << endl;
	for (int i = 0; i < ele; i++)
		cin >> a[i];

    cout << endl;

    BubbleSort(a, ele);

    return 0;
}
