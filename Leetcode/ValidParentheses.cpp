#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> str;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (!str.empty())
            {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                {
                    str.push(s[i]);
                }
                else
                {
                    if (s[i] == ')' && str.top() == '(')
                    {
                        str.pop();
                    }
                    else if (s[i] == '}' && str.top() == '{')
                    {
                        str.pop();
                    }
                    else if (s[i] == ']' && str.top() == '[')
                    {
                        str.pop();
                    }
                    else
                    {
                        str.push(s[i]);
                    }
                }
            }
            else
            {
                str.push(s[i]);
            }
        }
        if (str.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};