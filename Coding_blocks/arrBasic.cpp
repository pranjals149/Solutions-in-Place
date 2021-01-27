#include <iostream>
using namespace std;

// int main() {
//     int arr[10] = {1, 2, 3};
//     int len = sizeof(arr)/sizeof(arr[0]);
//     for (int i = 0; i < len; i++) {
//         cout << arr[i] << endl;
//     }
// }

int main() {
    int n = 5;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cout << a[i] << ',';
    }
}