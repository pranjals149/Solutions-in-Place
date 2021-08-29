#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    static bool compare(string a, string b)
    {
        return a.length() > b.length();
    }

    bool isSubSeq(string a, string b)
    {
        int count_a = 0;
        int count_b = 0;

        while (count_a < a.size() && count_b < b.size())
        {
            if (a[count_a] == b[count_b])
            {
                count_a++;
            }
            count_b++;
        }

        return count_a == a.size();
    }

    bool checkSubSeq(vector<string> &strs, string sub, int curr_idx)
    {
        for (int i = 0; i <= curr_idx; i++)
        {
            if (isSubSeq(sub, strs[i]))
            {
                return true;
            }
        }

        return false;
    }

    int findLUSlength(vector<string> &strs)
    {
        unordered_map<string, int> m;

        for (auto i : strs)
        {
            m[i]++;
        }

        sort(strs.begin(), strs.end(), compare);

        for (int i = 0; i < strs.size(); i++)
        {
            if (m[strs[i]] > 1)
            {
                continue;
            }
            if (!checkSubSeq(strs, strs[i], i - 1))
            {
                return strs[i].size();
            }
        }

        return -1;
    }
};