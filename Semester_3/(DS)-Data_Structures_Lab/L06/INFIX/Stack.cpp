#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top = -1;
    int arr[MAX];

    public:

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;
    }

    bool isFull(){
        if(top == MAX)
            return true;
        else
            return false;
    }

    void push(int element)
    {
        if(isFull())
            cout << "Stack Overflow";
        else {
            top++;
            arr[top] = element;
            cout << "Pushed " << element << endl;
        }
    }

    void pop()
    {
        if(isEmpty())
            cout << "Stack Underflow";
        else {
            cout << "Popped " << arr[top] << endl;
            top--;
        }
    }

    void display() {
   if(top>=0) {
      cout<<"Stack elements are:";

      for(int i=top; i>=0; i--)
      cout << arr[i] << " ";
      cout << endl;
   } 
   else
   cout<<"Stack Underflow";
}

};

int main(){
    Stack s;

    s.push(3);
    s.push(4);
    s.push(2);

    s.pop();
    s.pop();
    s.push(5);
    s.display();

}