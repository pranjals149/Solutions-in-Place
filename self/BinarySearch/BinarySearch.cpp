#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();

        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target < arr[mid])
            {
                e = mid - 1;
            }
            else if (target > arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};