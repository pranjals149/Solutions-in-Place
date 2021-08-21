#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> m;

        while (n != 1)
        {
            int sum = 0;

            while (n)
            {
                int r = n % 10;
                sum += r * r;
                n = n / 10;
            }

            if (m.find(sum) == m.end())
            {
                m[sum] = 1;
                n = sum;
                continue;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};