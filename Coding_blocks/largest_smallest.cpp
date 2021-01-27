#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n, larg, small;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int largest = INT_MAX;
    int smallest = INT_MIN;

    for (int i = 0; i < n; i++) {
        larg = max(largest, a[i]);
        small = min(smallest, a[i]);
    }

    cout << larg << endl;
    cout << small << endl;

    system("pause");
    return 0;
}

