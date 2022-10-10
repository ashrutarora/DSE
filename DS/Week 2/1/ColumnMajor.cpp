#include <iostream>
using namespace std;

int main(){
	
	int a, b, i, j, x, y;
	
	cout << "Enter the order of the Matrix: ";
	cin >> a >> b;
	
	int arr[a][b];
	
	cout << "\nEnter the elements of the Matrix: \n";
	
	//Input of Matrix
	
	for(i = 0; i< a; i++)
	{
		for(j= 0; j< b; j++)
		{
				cout << "\n arr["<<i<<"]["<<j<<"]= ";
				cin >> arr[i][j];
		}
	}
	
	//Output of Matrix
	
	cout << "\nMatrix is: \n";
	
	for(i = 0; i< a; i++)
	{
		for(j= 0; j< b; j++)
		{
			cout << "\t" << arr[i][j];
		}
		cout << "\n";
	}
	
	//2D TO 1D Array -> Row Major Order
	
	cout << "\n2D TO 1D Array: ";
	
	for(i = 0; i< a; i++)
	{
		for(j= 0; j< b; j++)
		{	
			cout << " " << arr[j][i];
		}
	}

	
	//Retrieving an element from the 1D array
	
	
	cout << "\nEnter the position of element to be retrieved from 1D array: \n";
	cin >> x >> y ;
	
	
		int index = ((y*b) + x);
		
		cout << "\nElement " << arr[x][y] << " is at position " << index ;	
		
	return 0;	
}
