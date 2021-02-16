#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> s;

        for (int i = 0; i < logs.size(); i++)
        {
            if (logs[i] == "../" && !s.empty())
                s.pop();
            else if (logs[i] == "./" || (logs[i] == "../" && s.empty()))
                continue;
            else
                s.push(logs[i]);
        }

        return s.size();
    }
};