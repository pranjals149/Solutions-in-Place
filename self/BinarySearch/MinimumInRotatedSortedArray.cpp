#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int binarySearch(vector<int> &nums, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (start == end)
            {
                return nums[start];
            }
            else if (nums[mid] > nums[end])
            {
                start = mid + 1;
            }
            else if (nums[mid] == nums[end])
            {
                end--;
            }
            else
            {
                end = mid;
            }
        }

        return INT_MIN;
    }

    int findMin(vector<int> &nums)
    {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};