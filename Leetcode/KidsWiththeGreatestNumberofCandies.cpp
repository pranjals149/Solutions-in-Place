#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res;
        int greatest = candies[0];

        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] > greatest)
            {
                greatest = candies[i];
            }
        }

        for (int i = 0; i < candies.size(); i++)
        {
            int num = candies[i] + extraCandies;
            if (num < greatest)
            {
                res.push_back(false);
            }

            else if (num >= greatest)
            {
                res.push_back(true);
            }
        }

        return res;
    }
};