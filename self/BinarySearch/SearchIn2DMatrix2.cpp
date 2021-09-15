#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        long long rows = matrix.size();
        long long col = matrix[0].size();

        int start = 0, end = col - 1;

        while (start < rows and end >= 0)
        {
            if (matrix[start][end] == target)
            {
                return true;
            }
            else if (matrix[start][end] > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return false;
    }
};