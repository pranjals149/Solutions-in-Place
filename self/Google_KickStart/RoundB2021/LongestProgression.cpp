#include <iostream>
#include <vector>

using namespace std;

int giveMaxLength(vector<int> &D)
{
    int n = D.size();
    int i = 0, j = 0, ans = 0;

    while (i < n)
    {
        j = i;
        while (j < n && D[j] == D[i])
            j++;

        //when no changes are made
        ans = max(ans, j - 1 + 1);

        //when 1 next difference is changed
        if (j < n)
        {
            ans = max(ans, j - i + 2);
        }

        //k+2 and beyond case (joining futher D[i])
        if (j + 1 < n and D[j] + D[j + 1] == 2 * D[i])
        {
            int jj = j + 2;

            while (jj < n and D[jj] == D[i])
                jj++;

            ans = max(ans, jj - i + 1);
        }
        i = j;
    }

    return ans;
}

int longProg()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> D;

    for (int i = 1; i < n; i++)
    {
        D.push_back(a[i] - a[i - 1]);
    }

    int ans = giveMaxLength(D);
    reverse(D.begin(), D.end());
    ans = max(ans, giveMaxLength(D));

    cout << ans;
}

int main()
{

    int t = 1;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        longProg();
        cout << '\n';
    }

    return 0;
}