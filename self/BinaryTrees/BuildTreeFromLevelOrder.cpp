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

node *levelOrderBuild()
{
    int d;
    cin >> d;

    node *root = new node(d);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            current->left = new node(c1);
            q.push(current->left);
        }

        if (c2 != -1)
        {
            current->right = new node(c2);
            q.push(current->right);
        }
    }

    return root;
}

int main()
{
    node *root = buildTree();
}