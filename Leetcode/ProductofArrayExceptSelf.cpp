#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> L(n, 1); // Left product
        vector<int> R(n, 1); // right product
        vector<int> result(n, 1);

        for (int i = 1; i < n; ++i)
        {
            L[i] = L[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; --i)
        {
            R[i] = R[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; ++i)
        {
            result[i] = L[i] * R[i];
        }

        return result;
    }
};