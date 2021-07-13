#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> dp;

int power(int n)
{
    if (n == 1)
    {
        return dp[n] = 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    if (n % 2 == 0)
    {
        return dp[n] = 1 + power(n / 2);
    }

    return dp[n] = 1 + power(3 * n + 1);
}

bool cmp(int x, int y)
{
    int xp = power(x);
    int yp = power(y);

    if (xp == yp)
    {
        return x < y;
    }

    return xp < yp;
}

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        vector<int> ans;

        for (int i = lo; i <= hi; i++)
        {
            ans.push_back(i);
        }

        sort(ans.begin(), ans.end(), cmp);

        return ans[k - 1];
    }
};