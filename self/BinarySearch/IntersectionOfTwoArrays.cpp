#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool binarySearch(vector<int> &arr, int target)
    {
        int start = 0, end = arr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target)
            {
                return true;
            }
            else if (arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return false;
    }
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s;
        vector<int> ans;

        if (nums1.size() < nums2.size())
        {
            sort(nums2.begin(), nums2.end());

            for (int i = 0; i < nums1.size(); i++)
            {
                if (binarySearch(nums2, nums1[i]))
                {
                    s.insert(nums1[i]);
                }
            }
        }
        else
        {
            sort(nums1.begin(), nums1.end());

            for (int i = 0; i < nums2.size(); i++)
            {
                if (binarySearch(nums1, nums2[i]))
                {
                    s.insert(nums2[i]);
                }
            }
        }

        for (auto i : s)
        {
            ans.push_back(i);
        }

        return ans;
    }
};