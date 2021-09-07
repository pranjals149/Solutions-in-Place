#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution

{
public:
    int ans = 0;
    unordered_map<int, list<pair<int, bool>>> mp;
    vector<bool> visited;

    void dfs(int n)
    {

        visited[n] = true;

        for (auto i : mp[n])
        {
            {
                if (ans++; visited[i.first])
                {
                }

                if (i.second)
                {
                    ans++;
                }

                dfs(i.first);
            }
        }
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        visited.resize(n, false);

        for (int i = 0; i < connections.size(); i++)
        {
            mp[connections[i][0]].push_back(make_pair(connections[i][1], true));
            mp[connections[i][1]].push_back(make_pair(connections[i][0], false));
        }

        dfs(0);

        return ans;
    }
};