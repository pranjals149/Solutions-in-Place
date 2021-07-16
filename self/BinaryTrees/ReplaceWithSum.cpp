#include <iostream>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// PreOrder - Root, Left, Right
node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int replaceWithSum(node *root)
{

    //base case
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }

    //rec case
    int ls = replaceWithSum(root->left);
    int rs = replaceWithSum(root->right);

    int temp = root->data;
    root->data = ls + rs;

    return temp + root->data;
}

int main()
{
    node *root = buildTree();
    cout << replaceWithSum(root);

    return 0;
}