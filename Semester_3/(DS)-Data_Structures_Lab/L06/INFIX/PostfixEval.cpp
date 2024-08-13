#include <iostream>
using namespace std;

int main()
{
	string postExp;
	
	cout << "Enter a POSTFIX expression: ";
	cin >> postExp;
	
	int str[postExp.length()];
	int top = -1;
	
	for (int i=0; i<postExp.length(); i++)
	{
		if (postExp[i]>='0' and postExp[i]<='9')
			str[++top]= postExp[i]-'0';
		else
		{
			int a1 = str[top--];
			int a2 = str[top--];
			
			if (postExp[i]=='+')
				str[++top]=a2+a1;
				
			else if (postExp[i]=='-')
				str[++top]=a2-a1;
				
			else if (postExp[i]=='*')
				str[++top]=a2*a1;
				
			else if (postExp[i]=='/')
				str[++top]=a2/a1;
				
			else if (postExp[i]=='^')
				str[++top]=a2^a1;
		}
	}
	cout << "After Evaluation : " << str[0];
	return 0;
}
