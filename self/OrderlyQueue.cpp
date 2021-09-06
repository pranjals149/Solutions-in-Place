#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        string ans = s;
        if (k == 1)
        {
            for (int i = 0; i < s.size(); i++)
            {
                ans = min(ans, s.substr(i) + s.substr(0, i));
            }
        }
        else
        {
            sort(ans.begin(), ans.end());
        }

        return ans;
    }
};