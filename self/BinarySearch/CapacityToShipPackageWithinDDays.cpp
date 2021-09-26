#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    bool isFeasible(vector<int> &weights, int days, int ans)
    {
        int sum = 0;
        int req_days = 1;

        for (int i = 0; i < weights.size(); i++)
        {
            if (sum + weights[i] > ans)
            {
                req_days++;
                sum = weights[i];
            }
            else
            {
                sum += weights[i];
            }
        }

        return req_days <= days ? true : false;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int sum = 0, max_ele = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            max_ele = max(max_ele, weights[i]);
        }

        int start = max_ele, end = sum, res = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (isFeasible(weights, days, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return res;
    }
};