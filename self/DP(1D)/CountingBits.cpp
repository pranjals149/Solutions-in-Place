#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i & (i - 1)] + 1;
        }

        return dp;
    }
};