#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int s = 0;
        int e = letters.size() - 1;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (target < letters[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }

        return letters[s % letters.size()];
    }
};