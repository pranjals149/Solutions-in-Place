//Top down

#include <iostream>

using namespace std;

int ladders_topdown(int n, int k, int dp[])
{
    if (n == 0)
        return 1;

    //lookup (only when doing with dp)
    if (dp[n] != 0)
        return dp[n];

    //recursive case
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
            ways += ladders_topdown(n - i, k, dp);
    }

    return dp[n] = ways;
}

int main()
{
    int n, k;
    int dp[100] = {0};
    cin >> n >> k;

    cout << ladders_topdown(n, k, dp) << endl;
    return 0;
}