#include <iostream>
using namespace std;

int consecInt(int a, int b){
	
	int t;
	
	if(a < b){
		t = a;
	}
	else{
		t = b;
	}
	
	c:
	int r = a % t;
	
	if(r == 0){
		
		r = b % t;
		
		if(r == 0){
			return t;
		}
	}
		t--;
		goto c;
}

int main() {
	
    int a, b, gcd;

    cout << "Enter 2 positive integers: ";
    cin >> a >> b;

	int result = consecInt(a, b);

    cout << "GCD of " << a << " and " << b << " using CONSECUTIVE INTEGER method " << " = " << result << endl;

    return 0;
}

