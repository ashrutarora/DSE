// NON RECURSIVE METHOD

/*
Write an algorithm for finding the Greatest Common Divisor (GCD) of two numbers using Euclid’s algorithm.
Write a program to implement the Euclid’s algorithm.
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {

    int r;

    while (b != 0) {

        r = a % b;
        a = b;
        b = r;
    }

    return c;
}

int main() {
    int a, b;
    
    cout << "Enter two positive integers: ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}
