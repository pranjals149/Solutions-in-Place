// Given weights and prices of n items, we need to put a subset of items in a bad of capacity W such that we get the maximum total value in the bag, also known as knapsack.

// Input
// N = 4    W = 11
// wts = [2,7,3,4]
// prices = {5, 20, 20, 10}

// Output
// 40

#include <iostream>
#include <vector>

using namespace std;

// Recursive case -- Top Down
int knapsack(int wts[], int prices[], int N, int W)
{
    // base case
    if (N == 0 or W == 0)
    {
        return 0;
    }

    //rec case
    int inc = 0, exc = 0;
    if (wts[N - 1] <= W)
    {
        inc = prices[N - 1] + knapsack(wts, prices, N - 1, W - wts[N - 1]);
    }

    exc = knapsack(wts, prices, N - 1, W);

    return max(inc, exc);
}

int main()
{
    int wts[] = {2, 7, 3, 4};
    int prices[] = {5, 20, 20, 10};

    int N = 4;
    int W = 11;

    cout << knapsack(wts, prices, N, W) << endl;
}