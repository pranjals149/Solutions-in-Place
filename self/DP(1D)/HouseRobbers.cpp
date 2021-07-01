#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
        {
            int op1 = dp[i - 2] + nums[i];
            int op2 = dp[i - 1];
            dp[i] = max(op1, op2);
        }

        return dp[n - 1];
    }
};