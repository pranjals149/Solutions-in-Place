#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;

        int r = matrix.size();
        int c = matrix[0].size();

        int startRow = 0;
        int endRow = r - 1;
        int startCol = 0;
        int endCol = c - 1;

        while (startRow <= endRow and startCol <= endCol)
        {
            //Starting Row
            for (int i = startCol; i <= endCol; i++)
            {
                res.push_back(matrix[startRow][i]);
            }
            startRow++;

            //Ending Column
            for (int i = startRow; i <= endRow; i++)
            {
                res.push_back(matrix[i][endCol]);
            }
            endCol--;

            if (startRow <= endRow)
            {
                for (int i = endCol; i >= startCol; i--)
                {
                    res.push_back(matrix[endRow][i]);
                }
                endRow--;
            }

            if (startCol <= endCol)
            {
                for (int i = endRow; i >= startRow; i--)
                {
                    res.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }

        return res;
    }
};