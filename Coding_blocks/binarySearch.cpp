#include <iostream>

using namespace std;


int binary_search(int a[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] == key) { return mid; }
        else if (a[mid] > key) { end = mid - 1; }
        else { end = mid + 1; }
    }
    return -1;
}

int main() {
    int n, key, a[n];
    cin >> n;
    cin >> key;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << binary_search(a, n, key) << endl;
    return 0;
}
