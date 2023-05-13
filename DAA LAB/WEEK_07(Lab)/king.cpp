#include <iostream>
using namespace std;

class node{
    public:
        int key;
        node* right;
        node* left;
};

node* createNode(node* root, int data){

    node* newNode = new node();

    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* insertNode(node* &root, int data){

    if(root == NULL){
        root = createNode(root, data);
        return root;
    }

    if(data < root->key){

        insertNode(root->left, data);
    }

    if(data > root->key){

        insertNode(root->right, data);
    }

    return root;
}

void inorder(node* root){

    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->key;
    inorder(root->right);
}

node* search(node* root, int data){

    while(root != NULL && root->key != data){

        root = data < root->key ? root->left : root->right;
    }
    return root;
}

int countNodes(node* root){

    if(root == NULL)
        return 0;

    else{

        return (countNodes(root->left) + countNodes(root->right) + 1);
    }
}

int height(node* root){

    if(root == NULL)
        return 0;

    else{

        int lHt = height(root->left);
        int rHt = height(root->left);

        if(lHt > rHt){

            return lHt+1;
        }
        else{
            return rHt+1;
        }
    }
}