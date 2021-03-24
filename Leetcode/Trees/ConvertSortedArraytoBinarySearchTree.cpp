#include <iostream>
#include <algorithm>
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
    TreeNode *treemake(vector<int> arr, int l, int r)
    {
        if (l > r)
            return NULL;

        int mid = (l + r) / 2;
        TreeNode *node = new TreeNode(arr[mid]);
        node->left = treemake(arr, l, mid - 1);
        node->right = treemake(arr, mid + 1, r);

        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int n = nums.size();
        return treemake(nums, 0, n - 1);
    }
};