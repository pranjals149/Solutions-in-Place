#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
    int i = 0;
    vector<int> ans;
    void find(TreeNode *root)
    {
        if (root == NULL)
            return;

        find(root->left);
        ans.push_back(root->val);
        find(root->right);
    }

    void check(TreeNode *root)
    {
        if (root == NULL)
            return;

        check(root->left);
        root->val = ans[i++];
        check(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        find(root);
        sort(ans.begin(), ans.end());
        check(root);
    }
};