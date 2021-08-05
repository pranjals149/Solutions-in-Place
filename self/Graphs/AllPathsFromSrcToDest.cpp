#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &path, int source, int dest)
    {
        path.push_back(source);

        if (source == dest)
        {
            res.push_back(path);
            return;
        }

        for (auto i : graph[source])
        {
            dfs(graph, res, path, i, dest);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> res;
        vector<int> path;

        int n = graph.size();

        if (n == 0)
        {
            return res;
        }

        dfs(graph, res, path, 0, n - 1);

        return res;
    }
};