#include <iostream>
using namespace std;

void linearSearch(int a[], int target, int ele)
{
    int temp = -1;

    for (int i = 0; i < ele; i++)
    {
        if (a[i] == target)
        {
            cout << "Element found at position: " << i + 1 << endl;
            temp = 0;
            break;
        }
    }

    if (temp == -1)
    {
        cout << "No Element Found" << endl;
    }
}

int binarySearch(int a[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (a[mid] == x)
      return mid;

    if (a[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main()
{

    cout << "Enter the number of elements in Array" << endl;
    int ele;
    cin >> ele;

    int arr[ele];

    cout << "Please enter elements of the Array" << endl;
    for (int i = 0; i < ele; i++){

        cin >> arr[i];
    }
    
    cout << "Please enter an element to search" << endl;
    int num;
    cin >> num;

    linearSearch(arr, num, ele);

    int result = binarySearch(arr,num,0, ele);

    if (result == -1)
    cout << "Not found" << endl;
  else
   cout << "Element is found at position " << result + 1 << endl;


    return 0;
}