#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int start = 1, end = n;

        while (start <= end)
        {
            long mid = start + (end - start) / 2;
            long sum = (mid * (mid + 1)) / 2;

            if (sum == n)
            {
                return (int)mid;
            }
            else if (sum > n)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return (int)end;
    }
};