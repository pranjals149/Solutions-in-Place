#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int start = 0;
        int end = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            start = max(start, nums[i]); // in the end of the loop this will contain the max item in the array
            end += nums[i];
        }

        //binary search
        while (start < end)
        {
            // try for the middle as potential ans
            int mid = start + (end - start) / 2;

            //calculate how many pieces you can divide this in with this max sum
            int sum = 0;
            int pieces = 1;

            for (int num : nums)
            {
                if (sum + num > mid)
                {
                    // you cannot add this in this subarray, make a new one
                    // say you add this num in new subarray then sum = num
                    sum = num;
                    pieces++;
                }
                else
                {
                    sum += num;
                }
            }

            if (pieces > m)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        return end; // because here start == end
    }
};