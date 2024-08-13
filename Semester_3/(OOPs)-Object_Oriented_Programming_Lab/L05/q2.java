//WEEK 5 - Q2


import java.util.Scanner;

public class q2 {

	public static void main(String[] args) {

		Scanner sh= new Scanner (System.in);

		System.out.println("Enter the size of the array : ");
		int n = sh.nextInt();

		System.out.println("Start entering the array elements : ");
		int array[] = new int[n];

		for (int i=0; i<n; i++)
			array[i]=sh.nextInt();

		AOI a = new AOI();
		a = new AOI (array,n);

		System.out.println("The array elements are : ");
		a.Print();

		System.out.println();

		System.out.println("Enter any element to be searched : ");
		int s = sh.nextInt();

		a.Search(s);

		System.out.println("Enter the indexes of the elements to be compared : ");
		int a1 = sh.nextInt();
		int a2 = sh.nextInt();

		a.Compare(a1, a2);
	}

}
class AOI
{
	int n;
	int arr[] = new int[n];
	AOI()
	{
		System.out.println("Default Constructor Called");
	}
	AOI (int ar[],int n)
	{
		System.out.println("Parameterized Constructor Called");
		arr = ar;
		this.n=n;
	}
	void Print()
	{
		for (int i=0; i<n; i++)
			System.out.print(arr[i]+"\t");
		System.out.println();
	}

	void Search(int x)
	{
		for(int i=0; i<n; i++)
		{
			if (arr[i]==x)
			{
				System.out.println(x+" found in the array");
				return;
			}
		}
		System.out.println(x+ "not found in the array");
	}

	void Compare (int n1, int n2)
	{
		if (n1>=n || n2>=n)
			System.out.println("Wrong Index Entered");

		else if (arr[n1] > arr[n2])
			System.out.println(arr[n1]+" is greater than "+arr[n2]);

		else if (arr[n1] == arr[n2])
			System.out.println(arr[n1]+" is equal to "+arr[n2]);

		else
			System.out.println(arr[n1]+" is less than "+arr[n2]);
	}
}
