//Write a program to find GCD using consecutive integer checking method and analyze its time efficiency.

#include <iostream>
using namespace std;

int consecInt(int a, int b){
	
	int t = (a < b) ? a : b;

    while (t > 0) {

        if(a % t == 0){
            if(b % t == 0){
                return t;
            }
        }
        t--;
    }
    return 1;
}

int main() {
	
    int a, b, gcd;

    cout << "Enter 2 positive integers: ";
    cin >> a >> b;

	int result = consecInt(a, b);

    cout << "GCD of " << a << " and " << b << " using CONSECUTIVE INTEGER method " << " = " << result << endl;

    return 69;
}

