#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &stones, vector<bool> &visited, int start)
    {
        visited[start] = true;

        int res = 0;

        for (int i = 0; i < stones.size(); i++)
        {
            if (!visited[i] and (stones[i][0] == stones[start][0] || stones[i][1] == stones[start][1]))
            {
                res = res + dfs(stones, visited, i) + 1;
            }
        }

        return res;
    }

    int removeStones(vector<vector<int>> &stones)
    {
        vector<bool> visited(stones.size(), false);
        int res = 0;

        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i])
            {
                continue;
            }
            res += dfs(stones, visited, i);
        }

        return res;
    }
};