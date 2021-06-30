// Count the no of BST that can be formed using N nodes, numbered from 1 to N.

// Input
// 3
// 4

// Output
// 5
// 14

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int countBST(int n)
{
    if (n == 0 or n == 1)
    {
        return 1;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int x = countBST(i - 1);
        int y = countBST(n - i);
        ans += x * y;
    }

    return ans;
}

int countBSTDP(int n, int dp[])
{
    if (n == 0 or n == 1)
    {
        return 1;
    }

    //lookup
    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int x = countBSTDP(i - 1, dp);
        int y = countBSTDP(n - i, dp);
        ans += x * y;
    }

    return dp[n] = ans;
}

int countBSTBottomUp(int n)
{
    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }

    return dp[n];
}

int main()
{
    int n = 3;

    int dp[100] = {0};

    cout << countBST(n) << endl;
    cout << countBSTDP(n, dp) << endl;
    cout << countBSTBottomUp(n) << endl;

    return 0;
}