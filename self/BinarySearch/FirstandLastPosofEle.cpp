#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target, bool findStartIndex)
    {
        int ans = -1;
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target < nums[mid])
            {
                e = mid - 1;
            }
            else if (target > nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                ans = mid;

                if (findStartIndex)
                {
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};

        int start = search(nums, target, true);
        int end = search(nums, target, false);

        ans[0] = start;
        ans[1] = end;

        return ans;
    }
};