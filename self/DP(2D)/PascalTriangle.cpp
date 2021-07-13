#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        ans.push_back(1);

        if (rowIndex == 0)
        {
            return ans;
        }

        for (int i = 0; i < rowIndex; i++)
        {
            for (int j = i; j > 0; j--)
            {
                ans[j] = ans[j] + ans[j - 1];
            }

            ans.push_back(1);
        }

        return ans;
    }
};