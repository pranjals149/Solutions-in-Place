#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0, j = 1;
    int count = 0;

    sort(a, a + n);

    while (i < n && j < n)
    {

        if (a[j] - a[i] > d)
        {
            i++;
            j++;
        }
        else
        {
            i += 2;
            j += 2;
            count++;
        }
    }

    cout << "Count is : " << count << endl;

    return 0;
}
