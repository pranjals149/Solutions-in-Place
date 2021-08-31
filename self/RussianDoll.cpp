#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    static bool compare(vector<int> a, vector<int> b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        vector<int> dp;

        sort(envelopes.begin(), envelopes.end(), compare);

        dp.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++)
        {
            int curr = envelopes[i][1];

            auto itr = lower_bound(dp.begin(), dp.end(), curr);

            if (itr == dp.end())
            {
                dp.push_back(curr);
            }

            else if (*itr > curr)
            {
                dp[itr - dp.begin()] = curr;
            }
        }

        return dp.size();
    }
};