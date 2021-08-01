#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        bool isBlank = true;
        int count = 0;

        if (s == " ")
        {
            return 0;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                isBlank = true;
            }

            else
            {
                if (isBlank == true)
                {
                    count = 0;
                }

                count++;
                isBlank = false;
            }
        }

        return count;
    }
};