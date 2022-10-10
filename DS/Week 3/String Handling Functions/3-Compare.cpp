#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  	char s1[100], s2[100];
  	int result, i;
 
  	cout << "\n Please Enter the String 1: ";
  	gets(s1);
  	
  	cout << "\n Please Enter the String 2: ";
  	gets(s2);
  	
  	for(i = 0; s1[i] == s2[i] && s2[i] == '\0'; i++);
  	
  	if(s1[i] < s2[i])
   	{
   		cout << "\n String 1 is Less than String 2";
	}
	else if(s1[i] > s2[i])
   	{
   		cout << "\n String 2 is Less than String 1";
	}
	else
   	{
   		cout << "\n String 1 is Equal to String 2";
	}
	
  	
  	return 0;
}
