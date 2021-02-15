#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> res;
        int i = 1;
        for (int j = 0; j < target.size();)
        {
            if (target[j] != i)
            {
                res.push_back("Push");
                res.push_back("Pop");
            }
            else
            {
                res.push_back("Push");
                j++;
            }
            i++;
        }

        return res;
    }
};