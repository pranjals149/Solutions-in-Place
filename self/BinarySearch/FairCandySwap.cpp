#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int n = aliceSizes.size(), m = bobSizes.size();

        sort(bobSizes.begin(), bobSizes.end());

        int sumA = 0, sumB = 0;

        for (int i : aliceSizes)
        {
            sumA += i;
        }

        for (int i : bobSizes)
        {
            sumB += i;
        }

        for (int i = 0; i < n; i++)
        {
            int aliceBar = aliceSizes[i];

            int start = 0, end = m - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                int bobBar = bobSizes[mid];

                int resA = sumA - (aliceBar - bobBar);
                int resB = sumB - (bobBar - aliceBar);

                if (resA == resB)
                {
                    return {aliceBar, bobBar};
                }
                else if (resA > resB)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        return {};
    }
};