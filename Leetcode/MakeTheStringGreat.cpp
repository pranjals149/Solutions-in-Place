#include <iostream>

using namespace std;

class Solution
{
public:
    bool shouldBeDeleted(char a, char b)
    {
        return (a != b && tolower(a) == tolower(b));
    }

    string makeGood(string s)
    {
        string ans;
        for (int i = 0; i < s.length(); i++)
        {

            if (ans.empty())
            {
                ans += s[i];
            }
            else if (shouldBeDeleted(ans[ans.size() - 1], s[i]))
            {
                ans.pop_back();
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};