#include <iostream>

using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        int max = '0';

        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] > max)
                max = n[i];
        }

        return max - '0';
    }
};