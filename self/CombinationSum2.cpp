#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void helper(vector<int> &candidates, vector<int> &curr, vector<vector<int>> &ans, int target, int curr_idx)
    {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }

        for (int i = curr_idx; i < candidates.size(); i++)
        {
            if (i > curr_idx and candidates[i] == candidates[i - 1])
            {
                continue;
            }

            if (candidates[i] <= target)
            {
                curr.push_back(candidates[i]);
                helper(candidates, curr, ans, target - candidates[i], i + 1);
                curr.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> ans;

        helper(candidates, curr, ans, target, 0);

        return ans;
    }
};