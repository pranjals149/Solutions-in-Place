#include <iostream>
#include <unordered_map>
#include <cstring>
#include <climits>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0;
        int j = 0;

        while (j < n)
        {
            if (nums[j] == 0)
            {
                k--;
            }

            if (k < 0)
            {
                if (nums[i] == 0)
                    k++;
                i++;
            }
            j++;
        }

        return j - i;
    }
};