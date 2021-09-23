#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0 || num == 1)
        {
            return true;
        }

        long long start = 1, end = num;

        while (start <= end)
        {
            long long mid = start + (end - start) / 2;

            long long m = mid * mid;

            if (m == num)
            {
                return true;
            }
            else if (m < num)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return false;
    }
};