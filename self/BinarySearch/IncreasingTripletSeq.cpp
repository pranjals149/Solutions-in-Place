#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &dp, int target, int end)
    {
        int start = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (dp[mid] == target)
            {
                return mid;
            }
            else if (dp[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }

    bool increasingTriplet(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT_MAX);

        for (int i = 0; i < nums.size(); i++)
        {
            int pos = binarySearch(dp, nums[i], i);

            dp[pos] = nums[i];

            if (pos == 2)
            {
                return true;
            }
        }

        return false;
    }
};