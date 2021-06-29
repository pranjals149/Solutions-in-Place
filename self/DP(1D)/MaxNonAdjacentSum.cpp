// Given an array of positive integers, find the max sum of non adjaent elements in the array

// Input
// [6, 10, 12, 7, 9, 14]

// output
// 32

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int max_sum(vector<int> arr, int n)
{
    vector<int> dp(n);

    dp[0] = arr[0];
    dp[1] = max(dp[0], dp[1]);

    for (int i = 2; i < n; i++)
    {
        int op1 = arr[i] + dp[i - 2];
        int op2 = dp[i - 1];

        dp[i] = max(op1, op2);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> arr{6, 10, 12, 7, 9, 14};
    int n = arr.size();

    cout << max_sum(arr, n) << endl;

    return 0;
}