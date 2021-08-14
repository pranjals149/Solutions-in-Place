#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        unordered_set<char> s;
        int count = 0;

        for (int i = 0; i < allowed.length(); i++)
        {
            s.insert(allowed[i]);
        }

        for (auto str : words)
        {
            bool flag = true;

            for (int i = 0; i < str.length(); i++)
            {
                if (s.find(str[i]) == s.end())
                { // Not found
                    flag = false;
                }
            }

            if (flag)
            {
                count++;
            }
        }

        return count;
    }
};