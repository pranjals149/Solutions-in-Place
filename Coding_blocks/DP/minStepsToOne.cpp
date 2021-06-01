#include <iostream>
#include <climits>

using namespace std;

// n-> n/3 .... n->n/2 .... n->n-1

int minSteps(int n, int dp[])
{
    //base case
    if (n == 1)
        return 0;

    //recursive case

    if (dp[n] != 0)
        return dp[n];

    //Compute if dp[n] is not known
    int op1, op2, op3;

    op1 = op2 = op3 = INT_MAX;

    if (n % 3 == 0)
    {
        op1 = minSteps(n / 3, dp);
    }

    if (n % 2 == 0)
    {
        op2 = minSteps(n / 2, dp);
    }

    op3 = minSteps(n - 1, dp);

    int ans = min(op1, op2, op3) + 1;
    return dp[n] = ans;
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};

    return 0;
}