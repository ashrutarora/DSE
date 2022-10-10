#include <iostream>
using namespace std;

struct Sparse{
	
	int row;
	int col;
	int value;
	
};

int main(){
	
	int count = 0;
	int n, m, i, j;
	
	cout << "Enter the order of the Matrix: ";
	cin >> m >> n;
	
	int arr[m][n];
	
	cout << "\nEnter the elements of the Matrix: \n";
	
	//Input of Matrix
	
	for(i = 0; i< m; i++)
	{
		for(j= 0; j< n; j++)
		{
				cout << "\n arr["<<i<<"]["<<j<<"]= ";
				cin >> arr[i][j];
				
				if(arr[i][j]!=0)
				count++;
		}
	}
	
	int k=1;
	
	struct Sparse S[count];
	
	S[0].row = m;
	S[0].col = n;
	S[0].value = count;
	
	
	// 1D array of triplets
	for(i = 0; i< m; i++)
	{
		for(j= 0; j< n; j++)
		{
				if(arr[i][j]>0)
				{
					S[k].row = i;
					S[k].col = j;
					S[k].value = arr[i][j];
					k++;
				}
		}
	}
	
	
	cout << "\nSparse Matrix: \n";
	
	for(i = 0; i< m; i++)
	{
		for(j= 0; j< n; j++)
		{
			cout << "\t" << arr[i][j];
		}
		cout << "\n";
	}
	
	cout <<"\nRow \tCoulumn \tValue\n";
	
	for(i = 0; i< count+1 ; i++)
	{
		cout << S[i].row<<"\t"<<S[i].col<<"\t"<<S[i].value;
		cout << "\n";
	}
	
	int b[S[0].row][S[0].col]= {};
	
	for(i = 0; i< S[0].value+1 ; i++)
	{
		 b[S[i].row][S[i].col]= (S[i].value);
	}
	
	//Reconstructed sparse matrix from 1D array of Trriplets
	
	cout << "\nReconstructed Sparse Matrix: " << endl ;
	
	for(i = 0; i< S[0].row ; i++)
	{
			for(j = 0; j< S[0].col ; j++)
			{
		 		cout << "\t" << b[i][j];
			}
			cout << "\n";
	}
	
	return 0;	
}
