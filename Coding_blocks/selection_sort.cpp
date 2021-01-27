#include <iostream>

using namespace std;

void selection_sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i; j <= n-1; j++) {
            if (a[j] < a[min_index]) { min_index = j;}
        }
        swap(a[i], a[min_index]);
    }
}

int main() {
    int n, a[n];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    selection_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ",";
    } 
    return 0;
}