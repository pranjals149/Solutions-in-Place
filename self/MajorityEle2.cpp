#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> res;
        unordered_map<int, int> m;

        for (auto num : nums)
        {
            m[num]++;
        }

        for (auto num : m)
        {
            if (num.second > nums.size() / 3)
            {
                res.push_back(num.first);
            }
        }

        return res;
    }
};