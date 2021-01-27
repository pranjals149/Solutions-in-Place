#include <iostream>

using namespace std;

int maxElement(int a[100], int n)
{

    int maxEl = a[0];

    for (int i = 0; i < n; i++)
    {
        if (a[i] > maxEl)
        {
            maxEl = a[i];
        }
    }
    return maxEl;
}
int main()
{
    int n, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << maxElement(a, n);
    return 0;
}