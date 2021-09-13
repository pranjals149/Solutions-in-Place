#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        long long n = matrix.size();
        long long m = matrix[0].size();

        long long start = 0, end = m - 1;

        while (start < n && end >= 0)
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

        return 0;
    }
};