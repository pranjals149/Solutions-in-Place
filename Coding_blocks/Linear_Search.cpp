#include <iostream>
using namespace std;

int main() {
    int n, key, i;
    cout << "Enter no. of elements: ";
    cin >> n;
    cout << "Enter Key to be searched: " << endl;
    cin >> key;

    int a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            cout << key << " found at index " << i << endl;;
            break;
        }
        else {
            cout << "Element not found" << endl;
        }
    }

}