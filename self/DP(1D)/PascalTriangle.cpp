#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        int dp[35][35];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < numRows; i++)
        {
            dp[i][0] = 1;
        }

        dp[1][1] = 1;

        for (int i = 2; i < numRows; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> res;

            for (int j = 0; j <= i; j++)
            {
                res.push_back(dp[i][j]);
            }

            ans.push_back(res);
        }

        return ans;
    }
};