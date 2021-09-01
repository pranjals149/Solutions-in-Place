#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double l;

        for (int i = 0; i < nums2.size(); i++)
        {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());

        if (nums1.size() % 2 == 0)
        {
            l = nums1[(nums1.size() / 2) - 1] + nums1[(nums1.size() / 2)];
        }
        else
        {
            return nums1[(nums1.size() / 2)];
        }

        return l / 2;
    }
};