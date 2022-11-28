#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    int i;
    char str[100];

    cout << "Enter a string: ";
    gets(str);

    for(i = 0; str[i]!= '\0' ; i++);

    cout << "The length of the string = " << i << endl;

    return 0;
}
