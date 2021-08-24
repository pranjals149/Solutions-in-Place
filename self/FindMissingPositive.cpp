#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int min_ele = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == min_ele)
            {
                min_ele++;
            }
        }

        return min_ele;
    }
};