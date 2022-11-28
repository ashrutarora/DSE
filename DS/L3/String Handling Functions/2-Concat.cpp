#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    int length;
    char s1[100], s2[100];

    cout<<"Enter the first string: " << endl;
    gets(s1);

    cout << "Enter the second string: " << endl;
    gets(s2);

    length = 0;
    while (s1[length] != '\0') 
    {
        ++length;
    }

    
    for (int j = 0; s2[j] != '\0'; ++j, ++length) 
    {
        s1[length] = s2[j];
    }

  
    s1[length] = '\0';

    cout << "After concatenation: " << s1;

    return 0;
}
