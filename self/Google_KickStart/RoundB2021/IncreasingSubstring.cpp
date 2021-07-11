#include <iostream>

using namespace std;

void incSubstr()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0 and s[i] > s[i - 1])
        {
            ans++;
        }
        else
        {
            ans = 1;
        }

        cout << ans << " ";
    }
}

int main()
{

    int t = 1;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        incSubstr();
        cout << '\n';
    }

    return 0;
}