#include <iostream>

using namespace std;

void spiralPrint(int a[][1000], int m, int n) {
    int startRow = 0;
    int startCol = 0;
    int endRow = 0;
    int endCol = 0;

    while(startRow <= endRow and startCol <= endCol) {
        for (int i = startCol; i < endCol; i++) {
            cout << a[startRow][i] << " ";
        }
        startRow++;

        //End Column
        for (int i = startRow; i < endRow; i++) {
            cout << a[i][endCol] << " ";
        }
        endCol--;

        //Bottom Row
        if (endRow > startRow) {
            for (int i = endCol; i >= startCol; i--) {
                cout << a[endRow][i] << " ";
            }
            endRow--;
        }

        //Start Column
        if (endCol > startCol) {
            for (int i = endRow; i >= startRow; i--) {
                cout << a[i][startRow] << " ";
            }
            startCol++;
        }
    }
}

int main() {
    int m, n, a[1000][1000];
    cin >> m >> n;

    int val = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = val;
            val += 1;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    spiralPrint(a, m, n);

    return 0;
}