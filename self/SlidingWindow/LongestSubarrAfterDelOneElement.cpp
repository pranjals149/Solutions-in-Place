#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int i = 0;
        int j = 0;

        int ans = 0;
        int prev = -1;

        while (i <= j and j < nums.size())
        {
            if (nums[j] == 1)
            {
                j++;
            }
            else
            {
                if (prev == -1)
                {
                    prev = j;
                }
                else
                {
                    ans = max(ans, j - i - 1);
                    i = prev + 1;
                    prev = j;
                }
                j++;
            }
        }

        ans = max(ans, j - i - 1);

        return ans;
    }
};