#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int idx = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                idx = i;
            }
        }

        return idx;
    }
};