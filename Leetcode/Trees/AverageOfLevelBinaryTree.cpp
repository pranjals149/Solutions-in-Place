#include <iostream>
#include <vector>
#include <queue>

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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<double> res;

        while (q.size())
        {
            double l = q.size();
            double sum = 0;

            for (int i = 0; i < l; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                sum += current->val;

                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }

            res.push_back(sum / l);
        }

        return res;
    }
};