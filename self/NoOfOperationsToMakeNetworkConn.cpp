#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void helper(unordered_map<int, vector<int>> &m, vector<bool> &visited, int curr_idx)
    {
        visited[curr_idx] = true;

        for (auto i : m[curr_idx])
        {
            if (!visited[i])
            {
                helper(m, visited, i);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        unordered_map<int, vector<int>> m;
        vector<bool> visited(n, false);

        for (int i = 0; i < connections.size(); i++)
        {
            m[connections[i][0]].push_back(connections[i][1]);
            m[connections[i][1]].push_back(connections[i][0]);
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                helper(m, visited, i);
                count++;
            }
        }

        return count - 1;
    }
};