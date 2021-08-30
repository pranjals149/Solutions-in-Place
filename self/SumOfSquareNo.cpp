#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long long a = 0; a <= sqrt(c); a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
            {
                return true;
            }
        }

        return false;
    }
};