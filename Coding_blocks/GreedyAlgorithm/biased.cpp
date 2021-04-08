#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {1, 2, 2, 1, 5, 7, 7};
    vector<int> b;
    int ans = 0;

    for (int i = 0; i < a.size(); i++)
    {
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < b.size(); i++)
    {
        ans += abs(a[i] - b[i]);
    }

    cout << ans << endl;
}