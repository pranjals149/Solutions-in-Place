#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }

        for (auto i : m)
        {
            if (i.second > n / 2)
            {
                return i.first;
            }
        }

        return 0;
    }
};