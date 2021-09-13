#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int helper(int k, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        if (k == 1)
        {
            return n;
        }

        if (dp[k][n] != -1)
        {
            return dp[k][n];
        }

        int start = 0, end = n, ans = INT_MAX;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            int a = helper(k - 1, mid - 1, dp);
            int b = helper(k, n - mid, dp);

            int temp = 1 + max(a, b);

            if (a > b)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }

            ans = min(ans, temp);
        }

        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, dp);
    }
};