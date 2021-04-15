#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        // 1 1 2 4 7 8
        sort(stones.begin(), stones.end());

        int n = stones.size();

        while (stones.size() >= 2)
        {
            int last = stones[n - 1];
            int secLast = stones[n - 2];

            stones.pop_back();
            stones.pop_back();
            n = n - 2;

            if (last != secLast)
            {
                stones.push_back(abs(last - secLast));
                n = n + 1;
            }

            sort(stones.begin(), stones.end());
        }

        if (stones.size() == 0)
            return 0;

        return stones[0];
    }
};