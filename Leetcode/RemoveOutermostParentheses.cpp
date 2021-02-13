#include <iostream>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        string res = "";

        int j = 0;

        for (int i = 0; i < S.size(); i++)
        {

            if (S[i] == ')')
            {
                j--;
            }

            if (j != 0)
            {
                res += S[i];
            }

            if (S[i] == '(')
            {
                j++;
            }
        }

        return res;
    }
};