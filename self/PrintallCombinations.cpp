// Write a program to print all the combinations of the given word with or without meaning(when unique characters are given).

//                                                                         Sample Input :

//     abc

//     Output :

//     abc

//     acb

//     bac

//     bca

//     cba

//     cab

#include <iostream>
#include <algorithm>

using namespace std;

void solve(string a, int start, int end)
{
    if (start == end)
    {
        cout << a << endl;
    }

    for (int i = start; i <= end; i++)
    {
        swap(a[start], a[i]);
        solve(a, start + 1, end);
        swap(a[start], a[i]);
    }
}

int main()
{
    string a;
    cin >> a;

    int n = a.length();

    solve(a, 0, n - 1);

    return 0;
}