#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        vector<int> dp(102, 0);

        dp[0] = 0;
        dp[1] = 1;

        if (n == 0)
            return dp[0];

        if (n == 1)
            return dp[1];

        for (int i = 1; i <= n / 2; i++)
        {
            dp[2 * i] = dp[i];
            dp[2 * i + 1] = dp[i] + dp[i + 1];
        }

        int ans = INT_MIN;

        for (int i = 0; i <= n; i++)
        {
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};