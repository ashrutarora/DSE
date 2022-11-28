#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100

class Stack {
    int top ;
    char arr[MAX];

    public:

    Stack(){
        top = -1;
    }

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

    void push(char element)
    {
        if(isFull());
            
        else {
            top++;
            arr[top] = element;
            
        }
    }

    char pop()
    {
        if(isEmpty()){
            return -1;
        }
        else {
            return arr[top--];
        }
    }

    char peek(){ 
        return arr[top];
    }

    void display() {
  
      cout<<"Stack: ";

      for(int i = top; i >= 0; i--)
      cout << arr[i] << " ";
      cout << endl;
}

};


string infix2postfix(string infix);
string infix2prefix(string infix);
void reverseStr(string& str);
void swapChars(char& a, char& b);
void bracketsRev(string& str);

int main(){

    // string infix = "((a/b)+c)-(d+(e*f))";
    string infix;
    
    cout<< "Enter INFIX String: ";
    cin >> infix;
    
    string postfix = "";
    string prefix = "";

    cout << endl << "Infix:  " << infix << endl << endl;

    postfix = infix2postfix(infix);
    cout << "Postfix:  " << postfix << endl << endl;

    prefix = infix2prefix(infix);
    cout << "Prefix:  " << prefix << endl;

}

int priority(char alpha){
    
    if(alpha == '+' || alpha == '+')
        return 1;
    if(alpha == '*' || alpha == '/')
        return 2;
    if(alpha == '^')
        return 3;

        return -1;
}

string infix2postfix(string infix){

    int i = 0;
    string postfix;
    Stack s;
    char x;

    while(infix[i] != '\0')
    {

        //OPERAND
        if( infix[i] >= 'a' && infix[i] <= 'z' ||
            infix[i] >= 'A' && infix[i] <= 'Z' ||
            infix[i] >= '0' && infix[i] <= '9' )
        {
            postfix += infix[i];
        }

        //LEFT PARENTHESIS
        else if(infix[i] =='(') {
            s.push(infix[i]);
        }

        //RIGHT PARENTHESIS
        else if(infix[i] == ')') {
            while(s.peek() != '(' && !s.isEmpty()){
                postfix += s.pop();
            }
            s.pop();
        }

        //OPERATOR
        else{
            while(!s.isEmpty() && s.peek() != '(' && priority(infix[i]) <= priority(s.peek()) ){
                
                postfix += s.pop();
            }
            s.push(infix[i]);
        }
        i++;
    }
    
     while(!s.isEmpty()){
        postfix += s.pop();
    }
    return postfix;
}

string infix2prefix(string infix){

    reverseStr(infix);
    // cout << "Reverse:  " << infix << endl;
    
    bracketsRev(infix);
    // cout << "Reversing brackets:  " << infix << endl;
    infix = infix2postfix(infix);
    
    reverseStr(infix);
    
    return infix;
}

void reverseStr(string& str)
{
    int n = str.length();
 
    for (int i = 0; i < n / 2; i++){
        // char temp = str[i];
        // str[i] = str[ n-i-1];
        // str[n-i-1] = temp;
        swapChars(str[i] , str[n-i-1]);
        
    }
}

void swapChars(char& a, char& b)
{
        char tmp = a;
        a = b;
      b = tmp;
}

void bracketsRev(string& str){
    
    for (int i=0; i < str.length(); i++) {
        if(str[i] == '(') {
            str[i] = ')';
        }    
        else if(str[i] == ')') {
            str[i] = '(';
        }    
    }
}


