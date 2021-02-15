#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> res;
        string ans = "";

        for (int i = 0; i < S.size(); i++)
        {
            if (res.size() == 0)
            {
                res.push(S[i]);
            }

            else if (res.top() != S[i])
            {
                res.push(S[i]);
            }

            else if (res.top() == S[i])
            {
                res.pop();
            }
        }

        while (!res.empty())
        {
            ans.push_back(res.top());
            res.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};