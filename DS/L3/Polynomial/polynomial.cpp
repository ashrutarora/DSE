#include <iostream>
using namespace std;

int max(int a, int b) {  return (a > b)? a: b; }

int *add(int A[], int B[], int a, int b)
{
   int size = max(a, b);
   int *sum = new int[size];

   for (int i = 0; i<a; i++)
     sum[i] = A[i];

   for (int i=0; i<b; i++)
       sum[i] += B[i];

   return sum;
}

void PolyPrint(int poly[], int b)
{
    for (int i=0; i<b; i++)
    {
       cout << poly[i];
       if (i != 0)
        cout << "x^" << i ;
       if (i != b-1)
       cout << " + ";
    }
}

int main()
{
    int a,b,i;
    
    cout << "Enter the number of terms in Polynomial 1: " << endl;
    cin >> a;
    
    int A[a];
    
    cout << "Enter the elements of Polynomial 1 (From number to highest degree of polynomial): " << endl;
    
    for( i=0 ; i<a ; i++)
    {
        cin >> A[i];
    }
    
    cout << "Enter the number of figures in Polynomial 2: " << endl;
    cin >> b;
    
    int B[b];
    
    cout << "Enter the elements of Polynomial 2 (From number to highest degree of polynomial): " << endl;
    
    for( i=0 ; i<b ; i++)
    {
        cin >> B[i];
    }
       

    int *sum = add(A, B, a, b);
    int size = max(a, b);

    cout << "Sum of polynomials is: " << endl;
    
    PolyPrint(sum, size);

    return 0;
}
