// There are N stones given in the form of an array, each element in array represents the height of its stone. There is a frog who is initially on Stone 1.

// Frog will repeat the following action some number of times to react stone N:
// 1. If the frog is currently on Stone i, jump to Stone i+1, or Stone i+2. Here, a cost of |hi- hj| is incurred, where j is the stone to land on.

// Find the minimum possible total cost incurred before the frog reaches stone N.

// Input
// 2
// 10 10 --- |10-10| = 0
//
// Output
// 0
//
// Input
// 6
// 30 10 60 10 60 50
//
// Output
// 40
//
// |30-60| + |60-60| + |60 - 50|

#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

//Bottom UP Approach
int getMinCost(vector<int> stones)
{
    int n = stones.size();
    vector<int> dp(n, 0);

    dp[1] = abs(stones[1] - stones[0]);

    for (int i = 2; i < n; i++)
    {
        int op1 = abs(stones[i] - stones[i - 1]) + dp[i - 1];
        int op2 = abs(stones[i] - stones[i - 2]) + dp[i - 2];
        dp[i] = min(op1, op2);
    }

    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> stones(n);

    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }

    cout << getMinCost(stones) << endl;

    return 0;
}