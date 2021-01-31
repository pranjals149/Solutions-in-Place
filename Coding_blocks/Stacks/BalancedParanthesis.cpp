#include <iostream>
#include <stack>

using namespace std;

bool isValid(char *s)
{
    stack<char> res;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];

        if (ch == '(')
        {
            res.push(ch);
        }

        else if (ch == ')')
        {
            if (res.empty() or res.top() != '(')
            {
                return false;
            }
            res.pop();
        }
    }

    return res.empty();
}

int main()
{
    char s[100] = "((a+b)+(c-d+f)))";
    if (isValid(s))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
