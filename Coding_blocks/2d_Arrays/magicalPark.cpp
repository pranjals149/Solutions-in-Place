// Piyush and magical Park

#include <iostream>

using namespace std;

void magicalPark(char a[][100], int m, int n, int k, int s)
{
    bool success = true;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char ch = a[i][j];

            //checking
            if (s < k)
            {
                success = false;
                break;
            }
            if (ch == '*')
            {
                s += 5;
            }
            else if (ch == '.')
            {
                s -= 2;
            }
            else
            {
                break;
            }

            // 1 Point reduction while moving forward except for the end of column
            if (j != n - 1)
            {
                s--;
            }
        }
    }

    if (success)
    {
        cout << "YES" << endl;
        cout << s << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int m, n, k, s;
    cin >> m >> n >> k >> s;

    char park[100][100];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> park[i][j];
        }
    }

    magicalPark(park, m, n, k, s);

    return 0;
}