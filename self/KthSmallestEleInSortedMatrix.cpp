#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        priority_queue<int> p;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                p.push(matrix[i][j]);
            }
        }

        while (p.size() > k)
        {
            p.pop();
        }

        return p.top();
    }
};