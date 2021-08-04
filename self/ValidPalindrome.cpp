#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'a' and s[i] <= 'z') || (s[i] >= 'A' and s[i] <= 'Z') || (s[i] >= '0' and s[i] <= '9'))
            {
                str += tolower(s[i]);
            }
        }

        int l = 0;
        int r = str.length() - 1;

        while (l <= r)
        {
            if (str[l] != str[r])
            {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};