#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int num1 = nums[0], maxVal = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        int temp = max(num1 + nums[i], nums[i]);
        if (temp > maxVal)
            maxVal = temp;
        num1 = temp;
    }
    return maxVal;
}