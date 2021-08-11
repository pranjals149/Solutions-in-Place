#include <iostream>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";

        for (int i = 1; i < n; i++)
        {
            int count = 1;
            string res = "";

            for (int j = 1; j < s.length(); j++)
            {
                if (s[j] == s[j - 1])
                {
                    count++;
                }
                else
                {
                    res += to_string(count);
                    res += s[j - 1];
                    count = 1;
                }
            }

            res += to_string(count);
            res += s.back();
            s = res;
        }

        return s;
    }
};