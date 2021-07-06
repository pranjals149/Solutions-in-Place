#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int helper(vector<int> &nums, vector<int> &mem, int currIndex)
    {
        if (currIndex >= nums.size() - 1)
        {
            return 0;
        }
        if (mem[currIndex] != INT_MAX)
        {
            return mem[currIndex];
        }
        if (nums[currIndex] == 0)
        {
            return INT_MAX;
        }
        for (int i = nums[currIndex]; i >= 1; i--)
        {
            int val = helper(nums, mem, currIndex + i);
            if (val != INT_MAX)
            {
                mem[currIndex] = min(mem[currIndex], 1 + val);
            }
        }
        return mem[currIndex];
    }
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> mem(n, INT_MAX);
        return helper(nums, mem, 0);
    }
};