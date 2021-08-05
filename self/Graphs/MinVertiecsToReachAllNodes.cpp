#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<bool> visited(n, false);
        vector<int> res;

        for (int i = 0; i < edges.size(); i++)
        {
            visited[edges[i][1]] = true;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};