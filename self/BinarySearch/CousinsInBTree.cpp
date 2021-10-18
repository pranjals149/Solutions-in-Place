/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> depth;
    vector<int> parent;

    void dfs(TreeNode *root, int parVal, int x, int y, int depthVal)
    {
        if (!root)
        {
            return;
        }

        if (root->val == x || root->val == y)
        {
            depth.push_back(depthVal);
            parent.push_back(parVal);
        }

        dfs(root->left, root->val, x, y, depthVal + 1);
        dfs(root->right, root->val, x, y, depthVal + 1);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, -1, x, y, 0);

        return depth[0] == depth[1] && parent[0] != parent[1];
    }
};