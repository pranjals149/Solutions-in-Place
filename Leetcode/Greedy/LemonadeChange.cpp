#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i] == 5)
            {
                five++;
                continue;
            }

            if (bills[i] == 10)
            {
                if (five > 0)
                {
                    ten++;
                    five--;
                }
                else
                    return false;
            }

            if (bills[i] == 20)
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }

                else if (five >= 3)
                {
                    five = five - 3;
                }

                else
                    return false;
            }
        }

        return true;
    }
};