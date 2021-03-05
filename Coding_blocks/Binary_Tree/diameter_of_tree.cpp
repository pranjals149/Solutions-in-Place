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

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int height(node *root)
{
    if (root == NULL)
        return 0;

    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void printKthLevel(node *root, int k)
{
    if (root == NULL)
        return;

    if (k == 1)
    {
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

void printAllLevels(node *root)
{
    int H = height(root);

    for (int i = 1; i < H; i++)
    {
        printKthLevel(root, i);
        cout << endl;
    }
    return;
}

void bfs(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *f = q.front();
        cout << f->data << " ";
        q.pop();

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return;
}

int count(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int diameter(node * root) {
    if (root == NULL) return 0;
    int h1 = height(root -> left);
    int h2 = height(root -> right);
    int op1 = h1+h2;
    int op2 = diameter(root -> left);
    int op3 = diameter(root -> right);

    return max(op1, max(op2, op3));
}

int main()
{
    node *root = buildTree();

    cout << diameter(root);

    return 0;
}
