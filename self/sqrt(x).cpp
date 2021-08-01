#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long long int low = 1, high = x, ans = 0;

        while (low <= high)
        {
            long long int mid = (low + high) / 2;
            long long int midsq = mid * mid;

            if (midsq == x)
            {
                return mid;
            }
            else if (midsq > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
                ans = mid;
            }
        }

        return ans;
    }
};