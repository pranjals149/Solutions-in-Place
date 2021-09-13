#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int j = 0;
        int min_len = INT_MAX;
        int pre_sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            pre_sum += nums[i];

            while (pre_sum >= target)
            {
                min_len = min(min_len, i - j + 1);
                pre_sum -= nums[j];
                j++;
            }
        }

        if (min_len != INT_MAX)
        {
            return min_len;
        }

        return 0;
    }
};