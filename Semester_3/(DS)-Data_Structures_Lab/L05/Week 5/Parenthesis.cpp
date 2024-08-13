#include<iostream>
#include<string.h>
# define MAX 100
using namespace std;

class stack{
	
	public:
	int top;
	char str[MAX];
	
	stack()
	{
		top = -1;
	}
	
	void push(char a)
	{
		if(top >= (MAX-1))
		{
			cout << "Stack Overflow"<<endl;
		}
		else
		{
			top++;
			str[top] = a;
		}
		
	}
	void pop()
	{
		if(top == -1)
		{
			cout << "Stack Underflow"<< endl;
		}
		else
		{	
			top--;
		}
	}
	
	bool isEmpty()
	{
		if(top == -1)
			return true;
			
		else
			return false;
	}
	
//	bool isFull()
//	{
//		if(top == MAX)
//			return true;
//			
//		else 
//			return false;
//	}
	
//	char peek()
//	{
//		return str[top];
//	}
	
	void display()
	{
	cout<<"Stack elements: ";
	      
	      for(int i=top; i>=0; i--)
	      cout<<str[i]<<" ";
	      cout<<endl;
	}
};

int main()
{
	stack s;
	char s1[100];
	
	cout << "Enter an expression: ";
	gets(s1);
	
	for(int i =0 ; s1[i]!='\0';i++)
	{
		if(s1[i] == '(' || s1[i] == '{' || s1[i] == '[')
		{
			s.push(s1[i]);
		}
		
		else if(s1[i] == ')')
		{
			if ( s.isEmpty() == true || s1[i] == '{' || s1[i] == '[')
			{
				cout << "Invalid Expression"<<endl;
			}
			else
			{
				s.pop();
			}
		}
		
		else if(s1[i] == '}')
		{
			if ( s.isEmpty() == true || s1[i] == '(' || s1[i] == '[')
			{
				cout << "Invalid Expression"<<endl;
			}
			else
			{
				s.pop();
			}
		}
		
		else if(s1[i] == ']')
		{
			if ( s.isEmpty() == true || s1[i] == '(' || s1[i] == '{')
			{
				cout << "Invalid Expression"<<endl;
			}
			else
			{
				s.pop();	
			}
		}	
	}

		if(s.isEmpty() == true)
		{
			cout << "It is a valid expression" << endl;	
		}
		else
		{
			cout << "It is an invalid expression" << endl;
			s.display();
		}
		
		
				
	return 0;
}
	
	

