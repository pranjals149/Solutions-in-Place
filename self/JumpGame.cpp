#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int curr_pos = 0;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0 and curr_pos == i)
            {
                return false;
            }

            else if (nums[i] + i >= curr_pos)
            {
                curr_pos = nums[i] + i;
            }
        }

        return curr_pos >= nums.size() - 1;
    }
};