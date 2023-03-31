#include <iostream>
using namespace std;

class Node {
    
    public:
        int data;
        Node *left;
        Node *right;
};

int maxDepth(Node* node){

    if (node == NULL)
        return 0;

    else{
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        if (lDepth > rDepth){
            return(lDepth + 1);
        }
        else{
            return(rDepth + 1);
        }
    }
}

Node* createNode(int data){

    Node* newNode = new Node();

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

Node* insertNode(Node* root, int data){

    if(root == NULL){

        root = createNode(data);
        return root;
    }
    if(data < root->data){

        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){

        root->right = insertNode(root->right, data);
    }

    return root;
}

int main(){

    Node* root = NULL;

    int n, val;

    cout<<"Enter the number of nodes you want to insert: ";
    cin>>n;

    cout<<"Enter the values of the nodes:\n";
    for(int i=0; i<n; i++){

        cin>>val;
        root = insertNode(root, val);
    }

    cout << "Height of tree is " << maxDepth(root);

    return 69;
}
