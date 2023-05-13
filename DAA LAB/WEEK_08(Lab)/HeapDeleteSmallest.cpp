#include<iostream>

using namespace std;

// Function to display the elements of an array
void display(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

// Function to heapify a subtree rooted with node i which is an index in arr[]
// n is size of heap
void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smallest as root
    int left = 2*i + 1; // Left child index
    int right = 2*i + 2; // Right child index
 
    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
 
    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
 
    // If smallest is not root
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// Function to delete the root element of a heap
void deleteRoot(int arr[], int &n)
{
    if (n == 0) // Heap is already empty
        return;
 
    // Replace the root element with the last element
    arr[0] = arr[n-1];
    n--; // Reduce the size of the heap
 
    // Heapify the root element
    heapify(arr, n, 0);
}

int main()
{

    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;

    int arr[n];

    cout<<"Enter "<<n<<" array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout << "\nUnsorted array:  \n";
    display(arr, n);
    
    // Build a min heap using bottom-up construction
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
        
    cout << "\nSorted Array:  \n";
    display(arr, n);
 
    cout << "\nSmallest element in the heap: " << arr[0] << "\n";
    
    // Delete the root element of the heap
    deleteRoot(arr, n);
 
    cout << "\nHeap after deleting smallest element:  \n";
    display(arr, n);
    
    return 0;
}
