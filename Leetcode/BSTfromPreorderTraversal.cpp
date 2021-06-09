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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);
        if (preorder.size() == 1)
            return root;

        vector<int> left_nodes;
        vector<int> right_nodes;

        for (int n : preorder)
        {
            if (n < preorder[0])
                left_nodes.push_back(n);
            else if (n > preorder[0])
                right_nodes.push_back(n);
        }

        root->left = bstFromPreorder(left_nodes);
        root->right = bstFromPreorder(right_nodes);

        return root;
    }
};