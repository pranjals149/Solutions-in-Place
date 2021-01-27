#include <iostream>
using namespace std;
int main()
{
    int nRow, nCol;
    cin >> nRow >> nCol;

    int a[nRow][nCol];

    //Take Input
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            cin >> a[i][j];
        }
    }
    //Iterating over each column
    for (int j = 0; j < nCol; j++)
    {
        if (j % 2 != 0)
        {
            //for odd column
            for (int i = nRow - 1; i >= 0; i--)
            {
                cout << a[i][j] << ", ";
            }
        }
        else
        {
            //for even column
            for (int i = 0; i < nRow; i++)
            {
                cout << a[i][j] << ", ";
            }
        }
    }
    cout << "END" << endl;
}