#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];

        if (n == 1)
        {
            ans.push_back({start, end});
            return ans;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (end >= intervals[i + 1][0] || start >= intervals[i + 1][0])
            {
                start = min(start, intervals[i + 1][0]);
                end = max(end, intervals[i + 1][1]);
            }
            else
            {
                ans.push_back({start, end});
                start = intervals[i + 1][0];
                end = intervals[i + 1][1];
            }

            if (i == n - 2)
            {
                ans.push_back({start, end});
            }
        }

        return ans;
    }
};