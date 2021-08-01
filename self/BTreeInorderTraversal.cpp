#include <iostream>
#include <vector>
#include <algorithm>

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
    void helper(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        if (root->left == NULL and root->right == NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        helper(root, ans);
        return ans;
    }
};