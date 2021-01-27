// Given a 2D array of size NxN. Rotate the image of NxN by 90deg anticlock wise in O(1) space.

#include <iostream>
#include <algorithm>

using namespace std;

void display(int a[][1000], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(int a[][1000], int n)
{
    //Reverse each row
    for (int row = 0; row < n; row++)
    {
        int start_col = 0;
        int end_col = n - 1;
        while (start_col < end_col)
        {
            swap(a[row][start_col], a[row][end_col]);
            start_col++;
            end_col--;
        }
    }

    //Taking transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
}

int main()
{
    int n, a[1000][1000];
    cin >> n;

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

    rotate(a, n);
    cout << endl;
    display(a, n);

    return 0;
}
