#include <iostream>
using namespace std;

int binomialCoeff(int n, int k){

    // n = Total Items
    // k = Items to be selected form n

    int C[n+1][k+1];

    // Runs till the number of items that we have = n
    for(int i=0; i <=n; i++){

        // Min is checked because we cant have more items than the maximum number of items
        for(int j = 0; j <= min(i, k); j++){

            // We have either selected all / none items 
            if(j == 0 || j == i){
                
                C[i][j] = 1;
            }
            else{
                // General formula for Binomial Coeff
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
    return C[n][k];
}
int main() {

    int n , k;

    cout << "Enter n : ";
    cin >> n;

    cout << "Enter k (should be less than OR equal to n) : ";
    cin >> k;

    cout << endl;

    if(k <= n){

        cout << "The binomial coefficient for n = " << n << " and k = " << k << " is " << binomialCoeff(n, k) << endl;
    }
    else{
        cout << "Enter a value of k greater than n" << endl;
    }
    return 0;
}