#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {

        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root) {
    
    int data;

    cout << "Enter Data: " << endl;
    cin >> data;

    if( data == -1){

        return NULL;
    }

    root = new Node(data);

    cout << "For LEFT of " << data << endl;
    root -> left = buildTree(root -> left);
    
    cout << "For RIGHT of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void inorder (Node* root){

    //Base Case
    if(root == NULL){
        
        return ;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder (Node* root){
    
    //Base Case
    if(root == NULL){
        
        return ;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder (Node* root){
    
    //Base Case
    if(root == NULL){
        
        return ;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int leafNodeCounter(Node* root){

    if(root == NULL){

        return 0;
    }

    if( root -> left == NULL && root -> right == NULL){

        return 1;
    }

    else{

        return leafNodeCounter(root -> left) + leafNodeCounter( root -> right);
    }
}

int main()
{

    Node* root = NULL;
    root = buildTree(root);

    cout << "Inorder traversal :";
    inorder(root);
    cout << endl;

    cout << "Preorder traversal :";
    preorder(root);
    cout << endl;

    cout << "Postorder traversal :";
    postorder(root);
    cout << endl;

    cout << "Number of leaf nodes = " << leafNodeCounter(root) << endl;
    
    return 0;
}