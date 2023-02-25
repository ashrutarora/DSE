#include <iostream>
using namespace std;

int gcd(int a, int b) {

    int c = a, d = b, r;

    while (d != 0) {

        r = c % d;
        c = d;
        d = r;
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
