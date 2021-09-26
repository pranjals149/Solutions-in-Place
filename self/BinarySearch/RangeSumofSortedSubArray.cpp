#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> helper;

        for (int i = 0; i < n; i++)
        {
            int temp = 0;
            for (int j = i; j < n; j++)
            {
                temp += nums[j];
                helper.push_back(temp);
            }
        }

        sort(helper.begin(), helper.end());

        unsigned long long res = 0;

        for (int i = left - 1; i < right; i++)
        {
            res += helper[i];
        }

        return res % (1000000007);
    }
};