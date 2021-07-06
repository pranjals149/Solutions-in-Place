#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void helper(string str, int open, int close, vector<string> &ans)
    {
        if (open == close and close == 0)
        {
            ans.push_back(str);
            return;
        }

        if (open > 0)
        {
            helper(str + "(", open - 1, close, ans);
        }

        if (close > open)
        {
            helper(str + ")", open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string str = "";

        helper(str, n, n, ans);

        return ans;
    }
};