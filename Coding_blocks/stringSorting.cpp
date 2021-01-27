// Sorting a given array of strings

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s[100];
    cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }
    sort(s, s+n);

    cout << "Sorted Elements are: " << endl;

    for (int i = 0; i < n; i++) {
        cout << s[i] << ",";
    }
    return 0;
}