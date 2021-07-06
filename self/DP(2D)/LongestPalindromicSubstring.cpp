#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        string str = "";

        vector<vector<int>> dp(n, vector<int>(n));

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if (gap == 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else
                {
                    if (s[i] == s[j] and dp[i + 1][j - 1] == 1)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }

                if (dp[i][j] == 1 and j - i + 1 > str.size())
                {
                    str = s.substr(i, j - i + 1);
                }
            }
        }

        return str;
    }
};