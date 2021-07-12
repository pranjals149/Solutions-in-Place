#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long rev = 0;
        long rem;

        while (x != 0)
        {
            rem = x % 10;
            rev = rev * 10 + rem;

            if (rev > INT_MAX || rev < INT_MIN)
            {
                return 0;
            }

            x = x / 10;
        }

        return (int)rev;
    }
};