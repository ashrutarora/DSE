#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class linkedList
{
private:
    Node *head;
public:
    linkedList()
    {
        head=NULL;
    }
    void addNode(int data)
    {
        Node* node=new Node;
        node->data=data;
        node->next=NULL;
        if(!head)
        {
            head=node;
        }
        else
        {
            Node *temp=head;
            while(temp->next)
            {
                temp=temp->next;
            }
            temp->next=node;
        }
        return;
    }
    void print()
    {
        Node* temp=head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main()
{
    linkedList ll;
    ll.addNode(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.print();
}