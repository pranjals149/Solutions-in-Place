#include <iostream>

using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int l = 0;
        int r = 0;
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                l++;
            else if (s[i] == 'R')
                r++;
            if (l == r)
            {
                count++;
                l = 0;
                r = 0;
            }
        }

        return count;
    }
};