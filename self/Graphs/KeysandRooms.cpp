#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void dfs(int src, vector<vector<int>> &rooms, vector<bool> &visited)
    {
        visited[src] = true;

        for (auto i : rooms[src])
        {
            if (!visited[i])
            {
                dfs(i, rooms, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();

        vector<bool> visited(n, false);
        dfs(0, rooms, visited);

        return count(visited.begin(), visited.end(), false) == 0;
    }
};