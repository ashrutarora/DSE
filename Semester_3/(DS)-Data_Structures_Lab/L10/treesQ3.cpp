#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root, int val)
{

    if (root == NULL)
    {

        return new Node(val);
    }

    if (val >= root->data)
    {

        root->right = buildTree(root->right, val);
    }

    else if (val < root->data)
    {

        root->left = buildTree(root->left, val);
    }

    return root;
}

Node* search(Node *root, int val){

    if(root == NULL || root -> data == val){

        return root;
    }

    if(val > root -> data){
        
        return search(root -> right, val);
    }

    return search(root -> left, val);
    
}

void inorder(Node *root)
{

    // Base Case
    if (root == NULL)
    {

        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* createTree(Node *root)
{

    int val;

    while (true)
    {

        cout << "Enter value: " << endl;
        cin >> val;

        if (val == -1){

            return root;
        }
        root = buildTree(root, val);
    }
}

int main()
{

    int val;

    Node *root = NULL;
    root = createTree(root);

    inorder(root);

    cout << endl << "Enter a value to be searched: " << endl;
    cin >> val;

    Node* result = search(root, val);

    if(result != NULL){

        cout << val << " found!" << endl;
    }
    else{

        cout << val << " not found!" << endl;
    }

    return 0;
}