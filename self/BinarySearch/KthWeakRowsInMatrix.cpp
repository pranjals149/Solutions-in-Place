#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    unordered_map<int, vector<int>> m;
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int start = 0, end = mat[0].size() - 1;

        vector<int> res, ans;

        for (int i = 0; i < mat.size(); i++)
        {
            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (mat[i][mid] == 1)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }

            res.push_back(start);

            start = 0;
            end = mat[0].size() - 1;
        }

        for (int i = 0; i < res.size(); i++)
        {
            m[res[i]].push_back(i);
        }

        sort(res.begin(), res.end());

        int cnt = 0;

        while (cnt < k)
        {
            vector<int> temp = m[res[cnt]];

            for (int i = 0; i < temp.size(); i++)
            {
                if (cnt == k)
                {
                    break;
                }

                ans.push_back(temp[i]);
                cnt++;
            }
        }

        return ans;
    }
};