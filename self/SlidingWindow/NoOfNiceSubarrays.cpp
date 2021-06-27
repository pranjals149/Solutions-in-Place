#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int solve(vector<int> &v, int k)
    {
        int i = 0;
        int j = 0;

        int count = 0;
        int ans = 0;

        while (j < v.size())
        {
            count += v[j];

            while (count > k)
            {
                count = count - v[i];
                i++;
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> v;

        for (int a = 0; a < nums.size(); a++)
        {
            if (nums[a] % 2 == 0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
        }

        return solve(v, k) - solve(v, k - 1);
    }
};