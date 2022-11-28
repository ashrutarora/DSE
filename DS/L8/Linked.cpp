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
void insertAtBeg(Node* &head, int d){

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void insertAtEnd(Node* &tail, int d){

    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;

}

void insertAtPos(Node* &head, Node* &tail, int pos, int d){

    //Insert at START
    if(pos == 1){
        insertAtBeg(head, d);
        return ;
    }

    Node* temp = head;
    int count = 1;

    while(count < pos-1)
    {
        temp = temp -> next;
        count++;
    }

    //Insert at END
    if (temp -> next == NULL){
        insertAtEnd(tail, d);
        return ;
    }

    //Creating a new node for DATA - d
     Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
}

void insertAfter(Node* &head, int val, int d){

    if(val == head -> data)
    {
        insertAtEnd(head, d);
        return;
    }

    Node* temp = head;
    Node* nodeToAdd = new Node(d);

    while (temp -> data != val && nodeToAdd !=NULL){

        temp = temp -> next;
    }

    if( temp -> data == val){

        nodeToAdd -> next = temp -> next;
        temp -> next = nodeToAdd;
    }
}

void insertBefore(Node* &head, int val, int d){

    if(val == head -> data)
    {
        insertAtBeg(head, d);
        return;
    }

    Node* temp = head;
    Node* temp1;
    Node* nodeToAdd = new Node(d);

    while(temp -> data != val){
        
        temp1 = temp;
        temp = temp -> next;
    }

    temp1 -> next = nodeToAdd;
    nodeToAdd -> next = temp;

}

void DeleteNode(Node* &head, Node* &tail, int pos){

    //Deleting the FIRST node
    if(pos == 1){
        Node* temp = head;

        head = head -> next;    //Head points the Next node
        temp -> next = NULL;
        delete temp;            //Frees the memory of the First node
    }
    //Deleting any other node
    else{
        
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        
        while (count < pos){
            
            prev = curr;
            curr = curr -> next;    
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

        //To update the Tail ptr
        if(curr -> next == NULL){
            tail = prev;
        }
    }
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
   cout<<"1) Insert at Beginning" << endl;
   cout<<"2) Insert at END" << endl;
   cout<<"3) Insert an element BEFORE element" << endl;
   cout<<"4) Insert an element AFTER element" << endl;
   cout<<"5) Delete Element" << endl;
   cout<<"6) Display" << endl;
   cout<<"7) Exit" << endl;

   int val, ch,d, pos;
   
   do {
      cout<<endl<<"Enter choice: "<<endl;
      cin>>ch;
      
      switch(ch) {
         case 1: {
            cout<<"Enter value to insert at BEG:"<<endl;
            cin>>val;
            insertAtBeg(head, val);
            break;
         }
         case 2: {
            cout<<"Enter value to insert at END:"<<endl;
            cin>>val;
            insertAtEnd(tail, val);
            break;
         }
         case 3: {
            cout<<"Enter value to insert before an element: "<<endl;
            cin>>d;

            cout << "Enter before which element to insert : "<< endl;
            cin >> val;

            insertBefore(head, val, d);
            break;
         }
         case 4: {
            cout<<"Enter value to insert after an element: "<<endl;
            cin>>d;

            cout << "Enter after which element to insert : "<< endl;
            cin >> val;

            insertAfter(head, val, d);
            break;
         }
         case 5: {

            cout<<"Enter position to delete: "<<endl;
            cin>>pos;

            DeleteNode(head, tail, pos);
            break;
         }
         case 6: {
            Display(head);
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
   }
   while(ch!=7);
    return 0;
}