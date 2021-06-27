#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int i = 0;
        int j = 0;

        int cs = 0;
        int ms = 0;

        unordered_map<int, bool> m;

        for (int idx = 0; idx < nums.size(); idx++)
        {
            while (m[nums[idx]] == true)
            {
                cs -= nums[i];
                m[nums[i]] = false;
                i++;
            }

            m[nums[idx]] = true;
            cs += nums[idx];
            ms = max(ms, cs);
        }

        return ms;
    }
};