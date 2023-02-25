#include <iostream>
using namespace std;

int gcd(int a, int b){
	
	if(a == 0){
		return b;
	}
	
	if(b == 0){
		return a;
	}
	
	return gcd(b, a % b);
}

int main(){
	
	int a, b;
	
	cout << "Enter 2 positive integers: ";
	cin >> a >> b;
	
	int result = gcd(a, b);
	
	cout << "GCD of " << a << " and " << b << " using EUCLIDS method"<<" = " << result << endl;
	
    return 0;
}
