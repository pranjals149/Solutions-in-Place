#include <iostream>
#include <climits>

using namespace std;

int max_profit(int prices[], int n)
{
    //base
    if (n <= 0)
        return 0;

    //rec case
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int cut = i + 1;

        int cur_ans = prices[i] + max_profit(prices, n - cut);
        ans = max(ans, cur_ans);
    }

    return ans;
}

int max_profit_dp(int *prices, int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int len = 1; len <= n; len++)
    {

        int ans = INT_MIN;
        for (int i = 0; i < len; i++)
        {
            int cut = i + 1;
            int cur_ans = prices[i] + dp[len - cut];
            ans = max(cur_ans, ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);

    cout << max_profit(prices, n) << endl;
}