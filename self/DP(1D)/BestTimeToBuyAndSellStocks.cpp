#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        if (n <= 1)
            return 0;

        int min_so_far = prices[0];
        int ans = 0;

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, prices[i] - min_so_far);
            min_so_far = min(min_so_far, prices[i]);
        }

        return ans;
    }
};