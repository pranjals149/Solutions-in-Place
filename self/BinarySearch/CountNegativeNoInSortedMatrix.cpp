#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int cnt = 0;
        int n = grid.size();

        for (int i = 0; i < n; i++)
        {
            int low = 0, high = grid[i].size();

            while (low < high)
            {
                int mid = low + (high - low) / 2;

                if (grid[i][mid] < 0)
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            cnt = cnt + (grid[i].size() - low);
        }

        return cnt;
    }
};