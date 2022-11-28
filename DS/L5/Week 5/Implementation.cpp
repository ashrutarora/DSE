#include<iostream>
using namespace std;
  
#define MAX 100
  
class Stack
{
   int top;
   public:
   int myStack[MAX]; 
  
   Stack() { top = -1; }
   
   void push(int val);
   void pop();
   int isEmpty();
   int isFull();
   int peek();
   void display();
};
   
void Stack::push(int val)
   {
      if (top >= (MAX-1)) 
	{
      cout << "Stack Overflow";
   	}
	else 
   {
	    top++;
		myStack[top] = val;
   }
}
  
void Stack::pop()
{
   if (top < 0)
	{
      cout << "Stack Underflow";
	}
	else 
	{
//    	int val = myStack[top];
    	cout << myStack[top] << " Popped" << endl;
		top--;
		
	}
}
  
int Stack::isEmpty()
{
   if(top == -1)
		cout << "Stack is Empty" << endl;
	else
		cout << "Stack is not Empty" << endl;
}

int Stack::isFull()
{
   if(top == MAX)
			cout << "Stack is Full" << endl;
		else
			cout << "Stack is not Full" << endl;
}

int Stack::peek()
{
	cout << "Peek: "<< myStack[top] <<endl;
}

void Stack::display()
{
	if(top>=0) 
	{
      cout<<"Stack elements: ";
      
      for(int i=top; i>=0; i--)
      cout<<myStack[i]<<" ";
      cout<<endl;
	} 
   else
   cout<<"Stack is empty";
}


int main()
{
	int val,ch;
	class Stack stack;
	
	
   cout<<"1) Push in Stack" << endl;
   cout<<"2) Pop from Stack" << endl;
   cout<<"3) Display Stack" << endl;
   cout<<"4) Is Stack Empty?" << endl;
   cout<<"5) Is Stack Full?" << endl;
   cout<<"6) Peek Stack" << endl;
   cout<<"7) Exit" << endl;
   
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      
      switch(ch) {
         case 1: {
            cout<<"Enter value to PUSH it:"<<endl;
            cin>>val;
            
            stack.push(val);
            break;
         }
         case 2: {
            stack.pop();
            break;
         }
         case 3: {
            stack.display();
            break;
         }
         case 4: {
            stack.isEmpty();
            break;
         }
         case 5: {
            stack.isFull();
            break;
         }
         case 6: {
            stack.peek();
            break;
         }
         case 7: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=7);
   
	return 0;
}
