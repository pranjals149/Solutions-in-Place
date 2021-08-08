#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> m;
        int count = 0;

        for (int i = 0; i < stones.length(); i++)
        {
            m[stones[i]]++;
        }

        for (int i = 0; i < jewels.length(); i++)
        {
            count += m[jewels[i]];
        }

        return count;
    }
};