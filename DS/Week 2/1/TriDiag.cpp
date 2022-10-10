#include <iostream>
using namespace std;

int main(){
	
	int a, i, j, x, y;
	
	cout << "Enter the order of the Square Matrix: ";
	cin >> a;
	
	int arr[a][a];
	
	cout << "\nEnter the elements of the TriDiagonal Matrix: \n";
	
	//Input of Matrix
	
	for(i = 0; i< a; i++)
	{
		for(j= 0; j< a; j++)
		{
			if(i ==j)
			{
				cout << "\narr["<<i<<"]["<<j<<"]= ";
				cin >> arr[i][j];
			}
			else if (i == j+1)
			{
				cout << "\narr["<<i<<"]["<<j<<"]= ";
				cin >> arr[i][j];
			}
			else if (i == j-1)
			{
				cout << "\narr["<<i<<"]["<<j<<"]= ";
				cin >> arr[i][j];
			}
			else
				arr[i][j]=0;	
		}
	}
	
	//Output of Matrix
	
	cout << "\nMatrix is: \n";
	
	for(i = 0; i< a; i++)
	{
		for(j= 0; j< a; j++)
		{
			cout << "\t" << arr[i][j];
		}
		cout << "\n";
	}
	
	//2D TO 1D Array -> Row Major Order
	
	cout << "\n2D TO 1D Array: ";
	
	for(i = 0; i< a; i++)
	{
		for(j= 0; j< a; j++)
		{
			if(i ==j)
			{
				cout << " " << arr[i][j];
			}
			else if (i == j+1)
			{
				cout << " " << arr[i][j];
			}
			else if (i == j-1)
			{
				cout << " " << arr[i][j];
			}	
		}
	}

	//Retrieving an element from the 1D array


	
	cout << "\nEnter the position of element to be retrieved from 1D array: \n";
	cin >> x >> y ;
	
	
	int index = (2*x + y);
	
		if(i==j)
	{
		cout << "\nElement " << arr[x][y]<< " is at position " << index;	
	}
		
	return 0;	
}
