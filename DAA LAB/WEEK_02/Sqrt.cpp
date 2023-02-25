#include <iostream>
using namespace std;

int sqrt(int n) {
	
    int x = n;
    int y = (x + 1) / 2;
    
    while (y < x) {
    	
        x = y;
        y = (x + n / x) / 2;
    }
    
    return x;
}

int main() {
	
    int n;
    
    cout << "Enter a positive integer: ";
    cin >> n;
    
    int sqrt_n = sqrt_floor(n);
    
    cout << "Square root of " << n << " = " << sqrt_n << endl;
    
    return 0;
}

