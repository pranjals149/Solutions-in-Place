#include <iostream>
#include <climits>
#include <vector>

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
    int count = 0;

    int findLeftHeight(TreeNode *root)
    {
        int count = 0;

        TreeNode *temp = root;

        while (temp)
        {
            count++;
            temp = temp->left;
        }

        return count;
    }

    int findRightHeight(TreeNode *root)
    {
        int count = 0;

        TreeNode *temp = root;

        while (temp)
        {
            count++;
            temp = temp->right;
        }

        return count;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        if (leftHeight == rightHeight)
        {
            return pow(2, leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};