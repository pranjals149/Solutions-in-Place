#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int helper(vector<int> &dp, int n)
    {
        if (n == 1)
            return dp[n] = 1;
        if (n == 2)
            return dp[n] = 2;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            ans += helper(dp, i - 1) * helper(dp, n - i);
        }

        return dp[n] = ans;
    }

    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        return helper(dp, n);
    }
};