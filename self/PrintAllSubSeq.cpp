#include <iostream>
#include <vector>

using namespace std;

string helper(int idx, string input, string ans, int n)
{
    if (idx >= n)
    {
        return ans;
    }

    // Take
    ans += input[idx];
    helper(idx + 1, input, ans, n);

    // Do not take
    int m = ans.size();
    ans = ans.substr(0, m - 1);

    helper(idx + 1, input, ans, n);
}

int main()
{
    //code

    string input = "abc";
    cout << helper(0, input, "", input.size());
    return 0;
}