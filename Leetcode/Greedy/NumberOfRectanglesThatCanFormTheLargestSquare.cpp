#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int maxLen = 0;
        int count = 0;

        for (int i = 0; i < rectangles.size(); i++)
        {
            int k = min(rectangles[i][0], rectangles[i][1]);

            if (k == maxLen)
                count++;

            else if (k > maxLen)
            {
                count = 1;
                maxLen = k;
            }
        }

        return count;
    }
};