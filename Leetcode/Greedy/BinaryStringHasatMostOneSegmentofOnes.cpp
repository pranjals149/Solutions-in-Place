#include <iostream>

using namespace std;

class Solution
{
public:
    bool checkOnesSegment(string s)
    {
        int count = 0;

        int n = s.size();

        if (!n || n == 1 || n == 2)
            return true;

        if (s[0] == '1')
            count = 1;

        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '1')
                count++;
            if (count > 1)
                return false;
        }

        return count < 2;
    }
};