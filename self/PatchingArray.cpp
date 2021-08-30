#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        unsigned int idx = 0;
        unsigned int ans = 0;
        unsigned int upto = 0;

        while (upto < n)
        {
            if (idx < nums.size() and nums[idx] <= upto + 1)
            {
                upto += nums[idx];
                idx++;
            }
            else
            {
                ans++;
                upto += upto + 1;
            }
        }

        return ans;
    }
};