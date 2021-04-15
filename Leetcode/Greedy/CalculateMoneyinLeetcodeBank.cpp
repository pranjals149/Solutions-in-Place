#include <iostream>

using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int sum = 0;
        int firstDay = 1;
        int count = firstDay;

        for (int i = 1; i <= n; i++)
        {
            sum += count;
            count++;

            if (i % 7 == 0)
            {
                firstDay++;
                count = firstDay;
            }
        }
        return sum;
    }
};