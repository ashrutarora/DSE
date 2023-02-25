#include <iostream>
using namespace std;

int gcd(int a, int b) {

    if (a == 0 && b == 0) {
        return -1; 
    }
    if (a == 0) {
        return b; 
    }
    if (b == 0) {
        return a; 
    }
    int smaller = (a < b) ? a : b;

    int result = 1;

    for (int i = 1; i <= smaller; i++) {

        if (a % i == 0 && b % i == 0) {

            result = i;
        }
    }
    return result;
}

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    
    if (result == -1) {

        cout << "Invalid input: both numbers are 0" << endl;
    }
    else {
        
        cout << "GCD of " << a << " and " << b << " is " << result << endl;
    }
    return 0;
}
