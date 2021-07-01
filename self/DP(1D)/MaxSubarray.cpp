#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = nums[0];

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        vector<int> dp(n);

        dp[0] = nums[0];

        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};