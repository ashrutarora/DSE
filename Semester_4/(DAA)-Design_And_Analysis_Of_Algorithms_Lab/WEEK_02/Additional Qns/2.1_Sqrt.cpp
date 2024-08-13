/*
Write a program for computing ⌊√n ⌋ for any positive integer and analyze its time efficiency. Besides assignment and comparison, your program may only use the four basic arithmetic operations.
*/

#include <iostream>
using namespace std;

double sqrt(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    double x = n, y = 1;
    double epsilon = 0.000001; // desired precision
    while (x - y > epsilon) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Square root of " << n << " is " << sqrt(n);
    return 0;
}
