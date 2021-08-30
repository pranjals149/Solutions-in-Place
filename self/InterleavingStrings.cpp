#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool check(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp)
    {
        if (i == s1.size() and j == s2.size())
        {
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i < s1.size() and s1[i] == s3[i + j])
        {
            bool c1 = check(s1, s2, s3, i + 1, j, dp);

            dp[i][j] = c1;

            if (c1)
            {
                return true;
            }
        }

        if (j < s2.size() and s2[j] == s3[i + j])
        {
            bool c2 = check(s1, s2, s3, i, j + 1, dp);

            dp[i][j] = c2;

            if (c2)
            {
                return true;
            }
        }

        dp[i][j] = false;

        return false;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return check(s1, s2, s3, 0, 0, dp);
    }
};