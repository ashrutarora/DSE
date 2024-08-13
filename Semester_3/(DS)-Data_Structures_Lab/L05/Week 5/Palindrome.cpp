#include <iostream>
#include <string.h>

using namespace std;
 
#define MAX 100

 
// Structure defining Stack data structure
class Stack{
	
	public:
	int top;
	char string[MAX];
	
	stack()
	{
		top = -1;
	}
 

bool isFull() 
{   
    if(top >= MAX-1)
        return true;
    else
        return false;
}
 

bool isEmpty() 
{
	 if(top == -1)
	     return true;
	 else
	     return false;
}
 

void push(int num) 
{
    if (isFull())
        cout << "Stack Overflow";
    else 
	{
		top++;
        string[top] = num;
        
    }
}
 
int pop() 
{
    if (isEmpty())
        cout << "Stack Underflow";
        
    else 
	{
     top--;
        return string[top+1];
    }
}
};

int main() 
{
    char inStr[100], c;
    int i, length;
    class Stack stack;
    
    cout << "Enter a string: ";
	gets(inStr);
    
    length = strlen(inStr);
    
    /* Push all characters of input String to Stack */
    for(i = 0; i < length; i++)
	{
        stack.push(inStr[i]);
    }
    
    /* Poping characters from stack returs the characters of input string
      in reverse order. We will then compare it with corresponding 
      characters of input string. If we found a mismatch the input 
      string is not a palindrome string */
      
    for(i = 0; i < length; i++)
	{
        if(stack.pop() != inStr[i]) 
		{
            cout << "Not Palindrome";
            return 0;
        }
    }
 
    cout << "Palindrome";
    return 0;
}
