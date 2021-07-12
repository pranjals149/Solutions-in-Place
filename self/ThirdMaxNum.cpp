#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;

        for (int i = 0; i < nums.size(); i++)
        {
            if (first < nums[i])
            {
                third = second;
                second = first;
                first = nums[i];
            }

            else if (second < nums[i] and nums[i] < first)
            {
                third = second;
                second = nums[i];
            }

            else if (third < nums[i] and nums[i] < second)
            {
                third = nums[i];
            }
        }

        return third == LONG_MIN ? first : third;
    }
};