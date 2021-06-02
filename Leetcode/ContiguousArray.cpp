#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;

        unordered_map<int, int> sum; // (sum and index)
        int count = nums[0] == 1 ? 1 : -1;

        sum[0] = -1;
        sum[count] = 0;

        int _max = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            count = nums[i] == 1 ? count + 1 : count - 1;

            if (sum.find(count) != sum.end())
            { // found
                _max = max(_max, i - sum[count]);
            }
            else
            {
                sum[count] = i;
            }
        }

        return _max;
    }
};