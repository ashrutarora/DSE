#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node *left;
        Node *right;
        
};

// Creating the ROOT node
Node* createNode(int data){

    Node* newNode = new Node();

    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

// Adding nodes to the ROOT node
Node* insertNode(Node* &root, int data){

    if (root == NULL){

        root = createNode(data);
        return root;
    }

    if(data < root->data){

        root->left = insertNode(root->left, data);
    }

    if(data > root->data){

        root->right = insertNode(root->right, data);
    }
    return root;
}

// Inorder
void inorder(Node* root){

    if(root == NULL)
    return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder
void preorder(Node* root){

    if(root == NULL)
    return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder
void postorder(Node* root){

    if(root == NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Search a node
Node* search(Node* root ,int data){

    while(root != NULL && root->data != data){

        root = data < root->data ? root->left : root->right;
    }
    return root;
}

// Count Number of Nodes
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
}

// Height of BST
int height(Node* root){

    if(root == NULL){
        return 0;
    }

    else{

        int lHt = height(root->left);
        int rHt = height(root->right);

        if(lHt > rHt){

            return(lHt + 1);
        }
        else{
            return(rHt + 1);
        }
    }
}

int main(){

    Node* root = NULL;

    int choice, val, x;

    do {
        cout << "Enter your choice: " << endl;
        cout << "1. Insert node" << endl;
        cout << "2. No of nodes" << endl;
        cout << "3. Search node" << endl;
        cout << "4. Inorder" << endl;
        cout << "5. Preorder" << endl;
        cout << "6. Postorder" << endl;
        cout << "7. Height of BST" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter the value to insert: ";
                cin >> val;
                root = insertNode(root, val);
                break;

            case 2:
                x = countNodes(root);
                cout << "No of nodes = " << x << endl;
                break;

            case 3:
                cout << "Enter the value to search: ";
                cin >> val;
                
                if(search(root, val) == NULL){
                    cout << "Not found" << endl;
                }
                else{
                    cout << "Found" << endl;
                }
                break;

            case 4:
                cout << endl << "Inorder : ";
                inorder(root);
                cout << endl;
                break;
            
            case 5:
                 cout << endl << "Preorder : ";
                preorder(root);
                cout << endl;
                break;

            case 6:
                cout << endl << "Postorder : ";
                postorder(root);
                cout << endl;
                break;

            case 7:
                x = height(root);

                cout << "Height of BST = " << x << endl;
                break;

            case 8:
                cout << "Exiting program" << endl;
                break;
            
            default:
                cout << "Invalid choice" << endl;
        }
    }while(choice != 7);

    return 69;
}