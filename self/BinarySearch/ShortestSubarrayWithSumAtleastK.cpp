#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        deque<int> q;
        int res = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0)
            {
                nums[i] += nums[i - 1];
            }

            if (nums[i] >= k)
            {
                res = min(res, i + 1);
            }

            while (q.size() && nums[i] - nums[q.front()] >= k)
            {
                res = min(res, i - q.front());
                q.pop_front();
            }

            while (q.size() && nums[i] <= nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);
        }

        if (res == INT_MAX)
        {
            return -1;
        }

        return res;
    }
};