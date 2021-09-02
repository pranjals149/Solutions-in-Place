#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int arrayNesting(vector<int> &nums)
    {
        int res = 0;
        int count, curr, prev;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
            {
                continue;
            }

            curr = nums[i];
            count = 1;
            nums[i] = -1;

            while (nums[curr] != -1)
            {
                prev = curr;
                curr = nums[curr];
                nums[prev] = -1;
                count++;
            }

            res = max(res, count);
        }

        return res;
    }
};