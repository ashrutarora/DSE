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
            int value = this ->  data;

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

    
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node* tail = newNode;

    Display(head);

    insertAtEnd(tail, 12);
    Display(head);

    insertAtEnd(tail, 15);
    Display(head);

    insertAtPos(head, tail, 4, 22);
    Display(head);

    DeleteNode(head, tail, 4);
    Display(head);

    insertAfter(head, 10, 18);
    Display(head);

    insertBefore(head, 15, 20);
    Display(head);

    // reverse(head);
    // Display(head);

    // DeleteData(head, tail, 10);
    // Display(head);

    cout << "Head : " << head -> data << endl;
    cout << "Tail : " <<  tail -> data << endl;

    return 0;
}