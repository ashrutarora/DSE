#include <iostream>
using namespace std;

class Node
{

    public: 
        int data;
        Node* next;

        Node(int data ){
            this -> data = data;
            this -> next = NULL;
        }

        //Destructor
        ~Node() {

            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }
        }
};

//reference is used so that we make changes in orig LL

void insertAtEnd(Node* &tail, int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;

}

void DeleteNode(Node* &head){

        Node* temp = head;

        head = head -> next;    //Head points the Next node
        temp -> next = NULL;
        delete temp;            //Frees the memory of the First node
}

void Display(Node* &head) {

    Node* temp = head;

    while ( temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

int main() {

    cout << "Enter the first element of Node: " << endl;
    int ele;
    cin >> ele;

    Node* newNode = new Node(ele);
    Node* head = newNode;
    Node* tail = newNode;

    cout<< "--------------------------------MENU--------------------------------" <<endl;
   
   cout<<"1) Insert " << endl;
   cout<<"2) Delete Element" << endl;
   cout<<"3) Display" << endl;
   cout<<"4) Exit" << endl;

   int val, ch;
   
   do {
      cout<<endl<<"Enter choice: "<<endl;
      cin>>ch;
      
      switch(ch) {
         
         case 1: {
            cout<<"Enter value to insert :"<<endl;
            cin>>val;

            insertAtEnd(tail, val);
            break;
         }
         case 2: {

            DeleteNode(head);
            break;
         }
         case 3: {
            Display(head);
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   while(ch!=4);
    return 0;
}