//Remove consecutive duplicates from a given string

#include <iostream>
#include <cstring>

using namespace std;

void removeDuplicates(char a[]) {
    int prev = 0;
    int l = strlen(a);
    if (l == 0 or l == 1) { return; }
    for (int current = 0; current < l; current++) {
        if (a[current] != a[prev]) {
            prev++;
            a[prev] = a[current];
        }
    }
    a[prev+1] = '\0';
    return;
}

int main() {
    
    char a[1000];
    cin.getline(a, 1000);
    removeDuplicates(a);
    cout << a << endl;

    return 0;
}
