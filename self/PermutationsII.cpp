#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        helper(nums, ans, 0);

        return ans;
    }

private:
    void helper(vector<int> nums, vector<vector<int>> &ans, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(nums);
        }

        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx and nums[i] == nums[idx])
            {
                continue;
            }

            swap(nums[i], nums[idx]);
            helper(nums, ans, idx + 1);
        }
    }
};