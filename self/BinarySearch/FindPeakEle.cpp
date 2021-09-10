#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] > nums[mid + 1])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }

        return s;
    }
};

// int orderAgnosticBS(MountainArray &mountainArr, int target, int start, int end)
// {
//     bool isAsc = mountainArr.get(start) < mountainArr.get(end);

//     while (start <= end)
//     {
//         int mid = start + (end - start) / 2;

//         if (mountainArr.get(mid) == target)
//         {
//             return mid;
//         }

//         if (isAsc)
//         {
//             if (target < mountainArr.get(mid))
//             {
//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid + 1;
//             }
//         }
//         else
//         {
//             if (target > mountainArr.get(mid))
//             {
//                 end = mid - 1;
//             }
//             else
//             {
//                 start = mid + 1;
//             }
//         }
//     }

//     return -1;
// }