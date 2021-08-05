#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> helper(n + 1, 0);

        for (auto i : trust)
        {
            helper[i[0]]--;
            helper[i[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (helper[i] == n - 1)
            {
                return i;
            }
        }

        return -1;
    }
};