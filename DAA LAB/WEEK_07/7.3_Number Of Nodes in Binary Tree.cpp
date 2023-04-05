// Find total number of nodes in a binary tree and analyze its efficiency

#include <iostream>
using namespace std;

// define TreeNode class to represent nodes in the binary tree
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // constructor to initialize a new node with the given value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// define BinaryTree class to represent the binary tree
class BinaryTree {
public:
    TreeNode* root;

    // constructor to initialize an empty binary tree
    BinaryTree() : root(NULL) {}

    // method to insert a new node with the given value into the binary tree
    void insert(int val) {
        if (root == NULL) {
            // if the root is null, create a new node and set it as the root
            root = new TreeNode(val);
            return;
        }
        // traverse the tree to find the appropriate place to insert the new node
        TreeNode* cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left == NULL) {
                    cur->left = new TreeNode(val);
                    return;
                }
                cur = cur->left;
            } else {
                if (cur->right == NULL) {
                    cur->right = new TreeNode(val);
                    return;
                }
                cur = cur->right;
            }
        }
    }

    // method to recursively count the total number of nodes in the tree
    int countNodes(TreeNode* node) {
        if (node == NULL) {
            // if the current node is null, return 0
            return 0;
        }
        // recursively count the number of nodes in the left and right subtrees
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // method to count the total number of nodes in the tree (starting from the root)
    int countNodes() {
        return countNodes(root);
    }
};

int main() {
    // create a new binary tree
    BinaryTree tree;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter " << n << " node values:\n";
    // prompt the user to enter the values of each node and insert them into the tree
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        tree.insert(val);
    }
    // count the total number of nodes in the tree and print it to the console
    int numNodes = tree.countNodes();
    cout << "Total number of nodes in the tree: " << numNodes << endl;
    return 0;
}
