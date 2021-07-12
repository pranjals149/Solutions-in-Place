#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s = "";
        int flag = 1;

        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[0][i] != strs[j][i])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag == 1)
            {
                s.push_back(strs[0][i]);
            }
            else
            {
                break;
            }
        }

        return s;
    }
};