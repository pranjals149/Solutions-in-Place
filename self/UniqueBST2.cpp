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
    vector<TreeNode *> helper(int s, int e)
    {
        vector<TreeNode *> ans;
        if (s > e)
        {
            return {NULL};
        }

        if (s == e)
        {
            return {new TreeNode(s)};
        }

        for (int i = s; i <= e; i++)
        {
            vector<TreeNode *> left = helper(s, i - 1);
            vector<TreeNode *> right = helper(i + 1, e);

            for (auto a : left)
            {
                for (auto b : right)
                {
                    ans.push_back(new TreeNode(i, a, b));
                }
            }
        }

        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> ans = helper(1, n);
        return ans;
    }
};