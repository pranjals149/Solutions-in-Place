#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    void check(TreeNode *node, vector<int> &arr)
    {
        if (!node)
            return;

        if (!node->left && !node->right)
        {
            arr.push_back(node->val);
            return;
        }

        check(node->left, arr);
        check(node->right, arr);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans1;
        vector<int> ans2;

        check(root1, ans1);
        check(root2, ans2);

        return ans1 == ans2;
    }
};