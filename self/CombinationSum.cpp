#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void helper(vector<int> &candidates, vector<int> &temp, int target, vector<vector<int>> &ans, int i, int curr_sum)
    {
        if (target == curr_sum)
        {
            ans.push_back(temp);
            return;
        }

        if (curr_sum >= target || i >= candidates.size())
        {
            return;
        }

        temp.push_back(candidates[i]);

        helper(candidates, temp, target, ans, i, curr_sum + candidates[i]);
        temp.pop_back();
        helper(candidates, temp, target, ans, i + 1, curr_sum);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(candidates, temp, target, ans, 0, 0);

        return ans;
    }
};