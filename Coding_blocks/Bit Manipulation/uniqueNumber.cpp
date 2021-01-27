// Find the unique number. Given list contains numbers occured twice. Only one number is occured once. Find the no.

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int no;
    int ans = 0;
    // Bitwise Operator
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        ans = ans ^ no;
    }

    cout << ans << endl;
    return 0;
}