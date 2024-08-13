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

Node *buildTree(Node *root)
{

    int data;

    cout << "Enter Data: " << endl;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {

        return NULL;
    }

    cout << "For LEFT of " << data << endl;
    root->left = buildTree(root->left);

    cout << "For RIGHT of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


void findParent(Node *root, int val, int parent)
{

    if (root == NULL)
    {

        return;
    }

    if (root->data == val)
    {

        cout << "Parent = " << parent << endl;
    }

    else
    {

        findParent(root->left, val, root->data);
        findParent(root->right, val, root->data);
    }
}

int findDepth(Node *root, int val)
{

    if (root == NULL)
    {

        return -1;
    }

    int dist = 0;

    if ((root->data == val) ||
        (dist = findDepth(root->left, val)) >= 0 ||
        (dist = findDepth(root->right, val)) >= 0)
    {

        return dist + 1;
    }
    return dist;
}

bool printAncestors(Node *root, int target)
{
  /* base cases */
  if (root == NULL)
     return false;
 
  if (root->data == target)
     return true;
 
  /* If target is present in either left or right subtree of this node,
     then print this node */
  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
 
  /* Else return false */
  return false;
}

int main()
{
    int val;

    Node *root = NULL;
    root = buildTree(root);

    cout << endl;
    cout << "Enter an ELEMENT to find its PARENT , Depth, Ancestors: ";
    cin >> val;

    cout << endl;
    findParent(root, val, -1);

    cout << endl;
    cout << "The depth of " << val << " = " << findDepth(root, val) << endl;

    cout << "Ancestors of " << val << " = ";
    printAncestors(root, val);
    
    return 0;
}