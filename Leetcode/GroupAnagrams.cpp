#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;

        if (strs.size() == 0)
            return result;

        unordered_map<string, vector<string>> map;

        for (string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        for (auto p : map)
        {
            result.push_back(p.second);
        }

        return result;
    }
};