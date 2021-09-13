#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        int start = 0, end = arr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (target < arr[mid])
            {
                end = mid - 1;
            }
            else if (target > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};