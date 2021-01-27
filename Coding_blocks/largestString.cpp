// Find the largest length and string from a given array of strings

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;

    char current[1000];
    char largest[1000];

    cin.get();

    int len = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        cin.getline(current, 1000);
        len = strlen(current);
        if (len > max_len) {
            max_len = len;
            strcpy(largest, current);
        }
    }

    cout << largest << " and " << max_len << endl;
    return 0;
}