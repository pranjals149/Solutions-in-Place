#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int start = 1, end = nums.size() - 1;
        int count;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            count = 0;

            for (int n : nums)
            {
                if (n <= mid)
                {
                    count++;
                }
            }

            if (count <= mid)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return start;
    }
};