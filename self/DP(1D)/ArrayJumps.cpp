// Given an array of positive integers, where each element represents the max no of steps you can jump forward in the array.
// Find mininum jumps needed to reach the final index.

// Input
// arr = [3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5]

// Output
// 4
// (3 --> 4 --> 2 --> 7 --> 5)

// for every position i , you can take a max jump upto arr[i].

// i.e. jump = arr[i]

//last index = n-1 ----- 0 steps needed for last index

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

//TopDown dp
int min_jumps(vector<int> arr, int n, vector<int> dp, int i = 0)
{

    //base case
    if (i == n - 1)
        return 0;

    if (i >= n)
        return INT_MAX;

    //rec case
    if (dp[i] != 0)
    {
        return dp[i];
    }

    //assume
    int steps = INT_MAX;
    int max_jump = arr[i];

    for (int jump = 1; jump <= max_jump; jump++)
    {
        int next_cell = i + jump;
        int subprob = min_jumps(arr, n, dp, next_cell);

        if (subprob != INT_MAX)
        {
            steps = min(steps, subprob + 1);
        }
    }

    return dp[i] = steps;
}

int main()
{
    vector<int> arr{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    int n = arr.size();

    vector<int> dp(n, 0);

    cout << min_jumps(arr, n, dp, 0) << endl;

    return 0;
}