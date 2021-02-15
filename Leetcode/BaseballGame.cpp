#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> res;

        for (int i = 0; i < ops.size(); i++)
        {

            if (ops[i] != "+" && ops[i] != "C" && ops[i] != "D")
            {
                res.push_back(stoi(ops[i]));
            }

            else if (ops[i] == "+")
            {
                res.push_back(res[res.size() - 1] + res[res.size() - 2]);
            }

            else if (ops[i] == "C")
            {
                res.erase(res.begin() + res.size() - 1);
            }

            else if (ops[i] == "D")
            {
                res.push_back(res[res.size() - 1] * 2);
            }
        }

        int sum = 0;

        for (int i = 0; i < res.size(); i++)
        {
            sum += res[i];
        }

        return sum;
    }
};