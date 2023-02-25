#include <iostream>

using namespace std;

// function to calculate prime factors of a given number
int primeFac(int n, int factors[]) {
    int count = 0;
    while (n % 2 == 0) {
        factors[count++] = 2;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[count++] = i;
            n /= i;
        }
    }
    if (n > 2) {
        factors[count++] = n;
    }
    return count;
}

// function to calculate the gcd of two numbers using the middle school method
int gcd(int m, int n) {

    int factors_m[100], factors_n[100];

    int count_m = primeFac(m, factors_m);
    int count_n = primeFac(n, factors_n);
    
    int common_factors[100];
    int count_common = 0;

    for (int i = 0; i < count_m; i++) {
        for (int j = 0; j < count_n; j++) {
            if (factors_m[i] == factors_n[j]) {
                common_factors[count_common++] = factors_m[i];
                factors_n[j] = -1;
                break;
            }
        }
    }
    int result = 1;
    for (int i = 0; i < count_common; i++) {
        result *= common_factors[i];
    }
    return result;
}

int main() {
    int a, b;
    int c;
    int exit_code = 49;
    cout << "Enter any two numbers : ";
    cin >> a >> b;
    c = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " using MIDDLE SCHOOL method " << " = " << c << endl;
    return 0;
}
