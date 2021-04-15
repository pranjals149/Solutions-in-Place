#include <iostream>

using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int res = 0, rem = 0;

        while (numBottles)
        {
            res += numBottles;

            numBottles += rem;

            rem = numBottles % numExchange;
            numBottles = numBottles / numExchange;
        }

        return res;
    }
};