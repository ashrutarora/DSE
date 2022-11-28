#include <iostream>
using namespace std;

int main()
{
	string preExp;
	
	cout << "Enter a POSTFIX expression: ";
	cin >> preExp;
	
	int str[preExp.length()];
	int top = -1;
	
	for (int i=preExp.length()-1; i>= 0; i--)
	{
		if (preExp[i]>='0' and preExp[i]<='9')
			str[++top]= preExp[i]-'0';
		else
		{
			int a1 = str[top--];
			int a2 = str[top--];
			
			if (preExp[i]=='+')
				str[++top]=a2+a1;
				
			else if (preExp[i]=='-')
				str[++top]=a2-a1;
				
			else if (preExp[i]=='*')
				str[++top]=a2*a1;
				
			else if (preExp[i]=='/')
				str[++top]=a2/a1;
				
			else if (preExp[i]=='^')
				str[++top]=a2^a1;
		}
	}
	cout << "After Evaluation : " << str[0];
	return 0;
}
