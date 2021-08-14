#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1 = "";
        string s2 = "";

        for (string str1 : word1)
        {
            s1 += str1;
        }

        for (string str2 : word2)
        {
            s2 += str2;
        }

        return s1 == s2;
    }
};