#include <iostream>
using namespace std;

class Node
{

    public: 
        int data;
        Node* next;
        Node* prev;

        Node(int data ){
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }

        //Destructor
        ~Node() {

            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }

            if(this -> prev != NULL){
                delete prev;
                this -> prev = NULL;
            }
        }
};

//reference is used so that we make changes in orig LL
void insertAtBeg(Node* &head, int d){

    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;

    cout << d << " inserted at HEAD."<< endl;
    cout << endl;
}


void insertAtEnd(Node* &head, int d){

    Node* temp = head;
    Node* nodeToAdd = new Node(d);

    while(temp->next != NULL){

        temp = temp -> next;
    }

    temp -> next = nodeToAdd;
    nodeToAdd -> prev = temp;
    nodeToAdd -> next = NULL;

    cout << d << " inserted at TAIL." << endl;
     cout << endl;
}

void insertAtPos(Node* &head, int pos, int d){

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
        insertAtEnd(head, d);
        return ;
    }

    //Creating a new node for DATA - d
     Node* nodeToInsert = new Node(d);

    temp -> next -> prev = nodeToInsert;
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

    cout << d << " inserted" << endl;
    cout << endl;
    
}

void insertAfter(Node* &head, int val, int d){

    if(val == head -> data){

        insertAtEnd(head,d);
        return;
    }

    Node* temp = head;
    Node* nodeToAdd = new Node(d);

    while (temp -> data != val && nodeToAdd !=NULL){

        temp = temp -> next;
    }

    if( temp -> data == val){

        temp -> next -> prev = nodeToAdd;
        nodeToAdd -> next = temp -> next;
        temp -> next = nodeToAdd;
        nodeToAdd -> prev = temp;
    }

    cout << d << " inserted after " << val << endl;
    cout << endl;
}

void insertBefore(Node* &head, int val, int d){

    if(val == head -> data){

        insertAtBeg(head,d);
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
    nodeToAdd -> prev = temp1;
    nodeToAdd -> next = temp;
    temp -> prev = nodeToAdd;

     cout << d << " inserted before " << val << endl;
     cout << endl;
}

void DeleteFromEnd(Node* head){

    Node* temp = head;

    while(temp->next != NULL){

        temp = temp -> next;
    }

    cout << "Deleted : " << temp -> data << endl;
    cout << endl;

    temp -> prev -> next = NULL;
    temp -> prev = NULL;
    temp -> next = NULL;
    delete temp;
}

void DeleteNode(Node* &head, int pos){

    //Deleting the FIRST node
    if(pos == 1){
        Node* temp = head;

        cout << "Deleted : " << temp -> data << endl;
        cout << endl;

        head = head -> next;    //Head points the Next node
        temp -> next = NULL;
        delete temp;            //Frees the memory of the First node
    }

    //Deleting any other node
    else{
        
        Node* curr = head;
        Node* prevN = NULL;

        int count = 1;
        
        while (count < pos){
            
            prevN = curr;
            curr = curr -> next;    
            count++;
        }

        cout << "Deleted : " << curr -> data << endl;
        cout << endl;

        prevN -> next = curr -> next;
        curr -> next -> prev = prevN;
        curr -> next = NULL;
        curr -> prev = NULL;
        delete curr;
    }
}


void Display(Node* &head) {

    Node* temp = head;

    cout << "Linked List: ";

    while ( temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {

    int firstEle;

    cout << "Enter the first element: " ;
    cin >> firstEle;

    cout << endl;


    Node* newNode = new Node(firstEle);
    Node* head = newNode;

    int choice;

    do{    
        cout << "--------------------------------DOUBLY LINKED LIST--------------------------------" <<endl;
        cout << "1) Insert element at END" << endl;
        cout << "2) Delete element from END" << endl;
        cout << "3) Insert element at HEAD" << endl;
        cout << "4) Insert element at A POSITION" << endl;
        cout << "5) Delete element from A POSITION" << endl;
        cout << "6) Insert element after Given Element" << endl;
        cout << "7) Insert element before Given Element" << endl;
        cout << "8) Display Linked List" << endl;
        cout << "9) END";

        cout << endl<<"Enter choice: "<<endl;
        cin >> choice;

        switch(choice){

                case 1: {

                    int val;
                    
                    cout << "Enter value of ELEMENT: "<<endl;
                    cin>>val;

                    insertAtEnd(head, val);
                    break;
                }

                case 2: {

                    DeleteFromEnd(head);
                    break;
                }

                case 3: {

                    int val;

                    cout << "Enter value of ELEMENT: "<<endl;
                    cin>>val;

                    insertAtBeg(head, val);
                    break;
                }

                case 4: {

                    int val, pos;

                    cout << "Enter value of ELEMENT: "<<endl;
                    cin >> val;

                    cout << "Enter position of ELEMENT to be ADDED at: "<<endl;
                    cin >> pos;

                    insertAtPos(head, pos, val);
                    break;
                }

                case 5: {

                    int pos;

                    cout << "Enter position of ELEMENT to be DELETED: "<<endl;
                    cin >> pos;
                    
                    DeleteNode(head, pos);
                    break;
                }

                case 6: {

                    int val, ele;

                    cout << "Enter value of ELEMENT: "<<endl;
                    cin >> val;

                    cout << "Enter value AFTER which ELEMENT to be ADDED: "<<endl;
                    cin >> ele;
                    
                    insertAfter(head, ele, val);
                    break;
                }

                case 7: {

                    int val, ele;

                    cout << "Enter value of ELEMENT: "<<endl;
                    cin >> val;

                    cout << "Enter value BEFORE which ELEMENT to be ADDED: "<<endl;
                    cin >> ele;
                    
                    insertBefore(head, ele, val);
                    break;
                }

                case 8: {

                    Display(head);
                    break;
                }

                case 9: {

                    cout<<"Exit"<<endl;
                    break;
                }

                default: {
                    cout<<"Invalid Choice"<<endl;
                }
        } 
    } while(choice != 9);
    return 0;
}