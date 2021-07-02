#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rotatedDigits(int n)
    {
        int count = 0;

        for (int i = 1; i <= n; i++)
        {
            int num = i;
            bool good = false;

            while (num)
            {
                int t = num % 10;

                if (t == 2 || t == 5 || t == 6 || t == 9)
                {
                    good = true;
                }

                else if (t == 3 || t == 4 || t == 7)
                {
                    good = false;
                    break;
                }

                num = num / 10;
            }

            if (good == true)
            {
                count++;
            }
        }

        return count;
    }
};