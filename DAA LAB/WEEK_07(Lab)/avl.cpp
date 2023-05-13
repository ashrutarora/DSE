#include <iostream>
using namespace std;

class Node{

    public:

        int val;
        Node* left;
        Node* right;
        int height;

    Node(int data){

        val = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node* node){

    if(node == NULL)
        return 0;
    
    return node->height;
}

int getBal(Node* node){

    if(node == NULL)
        return 0;
    
    return height(node->left) - height(node->right);
}

int max(int a, int b) {
        return (a > b) ? a : b;
    }

Node* right_rotate(Node* y){

    Node* x = y->left;
    Node* t2 = x->right;

    // Right rotation happens here
    x->right = y;
    y->left = t2;

    // Updating the heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* left_rotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int val) {

    // If the value is not present then we enter it into the tree
    if (node == NULL) {
        return new Node(val);
    }

    // Insertion as per BST
    if (val < node->val) {
        node->left = insert(node->left, val);
    }

    else if (val > node->val) {
        node->right = insert(node->right, val);
    }

    else {
        return node;
    }

    // Updating the height of the current node     
    node->height = 1 + max(height(node->left), height(node->right));

    // Magic of AVL starts here 
    int balance = getBal(node);

    //L
    if (balance > 1 && val < node->left->val) {

        return right_rotate(node);
    }

    //R
    if (balance < -1 && val > node->right->val) {

        return left_rotate(node);
    }

    //LR
    if (balance > 1 && val > node->left->val) {

        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    //RL
    if (balance < -1 && val < node->right->val) {

        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    return node;
}

void print_inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    cout << root->val << " ";
    print_inorder(root->right);
}


int main(){

    Node* root = nullptr;
    int n;

    cout << "Enter the number of nodes to be inserted: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cout << "Enter the value of node " << i+1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal of the AVL tree: ";
    print_inorder(root);
    cout << endl;

    return 0;
}
