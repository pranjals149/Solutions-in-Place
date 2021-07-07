#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void helper(vector<int> nums, vector<vector<int>> &ans, int curr_idx)
    {
        if (curr_idx == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        else
        {
            for (int i = curr_idx; i < nums.size(); i++)
            {
                swap(nums[curr_idx], nums[i]);
                helper(nums, ans, curr_idx + 1);
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int curr_idx = 0;
        helper(nums, ans, curr_idx);

        return ans;
    }
};