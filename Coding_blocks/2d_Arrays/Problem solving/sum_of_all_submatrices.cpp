// Find a given element in a sorted 2D array in staircase manner.

#include <iostream>

using namespace std;

int sum_of_subMatrices(int a[][1000], int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tl = (i + 1) * (j + 1);
            int br = (n - i) * (m - j);
            sum += (tl * br) * a[i][j];
        }
    }
    return sum;
}

int main()
{
    int n, a[1000][1000], m;
    cin >> m >> n;

    int val = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = val;
            val += 1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << sum_of_subMatrices(a, m, n);

    return 0;
}