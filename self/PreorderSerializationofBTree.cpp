#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int a = 0, b = 0;

        for (int i = 0; i < preorder.size(); i++)
        {
            if (b > a)
                return false;

            if (preorder[i] == '#')
            {
                b++;
            }
            else
            {
                a++;
            }

            while (i < preorder.size() and preorder[i] != ',')
            {
                i++;
            }
        }

        return a == b - 1;
    }
};