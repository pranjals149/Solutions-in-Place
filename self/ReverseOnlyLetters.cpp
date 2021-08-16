#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseOnlyLetters(string s)
    {
        string res = s;

        int start = 0;
        int end = res.size() - 1;

        while (start < end)
        {
            if (!isalpha(res[start]))
            {
                start++;
            }
            else if (!isalpha(res[end]))
            {
                end--;
            }
            else
            {
                char temp = res[start];
                res[start] = res[end];
                res[end] = temp;
                start++;
                end--;
            }
        }

        return res;
    }
};