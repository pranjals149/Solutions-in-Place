#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int count(vector<int> &arr, int t)
    {
        int cnt = 0;

        for (int i : arr)
        {
            if (i >= t)
            {
                cnt++;
            }
        }

        return cnt;
    }

    int specialArray(vector<int> &nums)
    {
        int start = 0, end = nums.size();

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            int curr = count(nums, mid);

            if (curr == mid)
            {
                return mid;
            }
            else if (curr < mid)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
};