#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int max_ele = arr[0];

        for (int i = 0; i < arr.size(); i++)
        {
            max_ele = max(max_ele, arr[i]);
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == max_ele)
            {
                return i;
            }
        }

        return 0;
    }
};