#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int odd = 0, even = 0;

        for (int i = 0; i < position.size(); i++)
        {
            if (position[i] % 2 == 0)
                even++;
            else
                odd++;
        }

        if (odd == even)
            return odd;

        return min(odd, even);
    }
};