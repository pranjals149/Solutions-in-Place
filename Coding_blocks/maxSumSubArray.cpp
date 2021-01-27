#include <iostream>

using namespace std;

int main() {
    int n, a[n];
    cin >> n;
    int largestSum = 0;
    int currentSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += a[k];
            }
            if (currentSum > largestSum) { largestSum = currentSum; }
        }
    }
    cout << "Largest sum: " << largestSum;
    return 0;
}