#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> sum;
        int add = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            add += nums[i];
            sum.push_back(add);
        }

        return sum;
    }
};