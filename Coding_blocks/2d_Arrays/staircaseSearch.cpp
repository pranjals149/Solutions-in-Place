// Find a given element in a sorted 2D array in staircase manner.

#include <iostream>

using namespace std;

bool search(int a[][1000], int n, int k) {
    int i = 0;
    int j = n - 1;
    while (i <= j) {
        if (a[i][j] == k) {
            return true;
        }
        else if (a[i][j] < k) {
            i++;
        }
        else if (a[i][j] > k) {
            j--;
        }
    }
    return false;
}

int main()
{
    int n, a[1000][1000], k;
    cin >> n >> k;

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

    cout << search(a, n, k);

    return 0;
}