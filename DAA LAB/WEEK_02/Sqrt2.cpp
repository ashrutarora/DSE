#include <iostream>
using namespace std;

int sqrt(int x) {
        int i =1,count=0; 
        while(x != 0){
        	
            x-=i;
            count++;
            i+=2;
            
            if(x < 0){
            	
                count--;
                break;
            }
        }
        return count;
    }

int main() {
	
    int n;
    
    cout << "Enter a positive integer: ";
    cin >> n;
    
    int sqrt_n = sqrt(n);
    cout << "Square root of " << n << " = " << sqrt(n) << endl;
    
    return 0;
}

