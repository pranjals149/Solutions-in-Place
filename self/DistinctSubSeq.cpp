#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    int helper(string &s, string &t, int i, int j)
    {
        if (j == t.size())
        {
            return 1;
        }
        if (i == s.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = helper(s, t, i + 1, j + 1) + helper(s, t, i + 1, j);
        }
        else
        {
            return dp[i][j] = helper(s, t, i + 1, j);
        }
    }

    int numDistinct(string s, string t)
    {
        memset(dp, -1, sizeof(dp));

        return helper(s, t, 0, 0);
    }
};
class Solution
{
public:
    int dp[1001][1001];

    int helper(string &s, string &t, int i, int j)
    {
        if (j == t.size())
        {
            return 1;
        }
        if (i == s.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == t[j])
        {
            return dp[i][j] = helper(s, t, i + 1, j + 1) + helper(s, t, i + 1, j);
        }
        else
        {
            return dp[i][j] = helper(s, t, i + 1, j);
        }
    }

    int numDistinct(string s, string t)
    {
        memset(dp, -1, sizeof(dp));

        return helper(s, t, 0, 0);
    }
};