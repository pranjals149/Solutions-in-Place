//Bottom UP appraoch

#include <iostream>
#include <climits>

using namespace std;

int minCoins(int n, int coins[], int T, int dp[])
{
    if (n == 0)
        return 0;

    //lookup
    if (dp[n] != 0)
        return dp[n];

    //recursive case
    int ans = INT_MAX;
    for (int i = 0; i < T; i++)
    {
        if (n - coins[i] >= 0)
        {
            int subprob = minCoins(n - coins[i], coins, T, dp);
            ans = min(ans, subprob + 1);
        }
    }

    dp[n] = ans;
    return dp[n];
}

//Bottom Up Approach
int minCoinsBU(int N, int coins[], int T)
{
    int dp[100] = {0};

    //itrate over all states from 1 to N
    for (int n = 1; n <= N; n++)
    {

        dp[n] = INT_MAX;
        for (int i = 0; i < T; i++)
        {
            if (n - coins[i] >= 0)
            {
                int subprop = dp[n - coins[i]];
                dp[n] = min(dp[n], subprop + 1);
            }
        }
    }

    return dp[N];
}

int main()
{
    int N = 15;
    int coins[] = {1, 7, 10};
    int dp[100] = {0};
    int T = sizeof(coins) / sizeof(int);

    cout << minCoinsBU(N, coins, T) << endl;

    return 0;
}
