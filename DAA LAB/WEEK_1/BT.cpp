#include <iostream>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

class BinaryTree {
private:
    Node* root;

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node != NULL) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

public:
    BinaryTree() {
        this->root = NULL;
    }

    void insert(int key) {
        Node* new_node = new Node(key);
        if (root == NULL) {
            root = new_node;
        } else {
            Node* current = root;
            while (true) {
                if (key < current->key) {
                    if (current->left == NULL) {
                        current->left = new_node;
                        break;
                    } else {
                        current = current->left;
                    }
                } else if (key > current->key) {
                    if (current->right == NULL) {
                        current->right = new_node;
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    cout << "Key already exists in the tree" << endl;
                    delete new_node;
                    return;
                }
            }
        }
    }

    void search(int key) {
    Node* current = root;
    Node* parent = NULL;
    while (current != NULL) {
        if (key < current->key) {
            parent = current;
            current = current->left;
        } else if (key > current->key) {
            parent = current;
            current = current->right;
        } else {
            cout << "Key found" << endl;
            return;
        }
    }
    // Key not found, add it to the tree
    Node* new_node = new Node(key);
    if (parent == NULL) {
        // Tree is empty
        root = new_node;
    } else if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    cout << "Key added to the tree" << endl;
}

    void displayInorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bst;

    int option;
    while (true) {
        cout << "Enter an option (1: insert, 2: search, 3: inorder, 4: preorder, 5: postorder, 6: exit): ";
        cin >> option;

        switch (option) {
            case 1: {
                int key;
                cout << "Enter a key to insert: ";
                cin >> key;
                bst.insert(key);
                break;
            }
            case 2: {
                int key;
                cout << "Enter a key to search: ";
                cin >> key;
                bst.search(key);
                break;
            }
            case 3: {
                bst.displayInorder();
                break;
            }
            case 4: {
                bst.displayPreorder();
                break;
            }
            case 5: {
                bst.displayPostorder();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }
}

