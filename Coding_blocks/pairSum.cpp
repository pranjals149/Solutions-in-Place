// Given a sorted array find the sub-array whose sum evaluates to k(given)

#include <iostream>
using namespace std;

int main() {

    int a[] = {1, 2, 3, 4, 5};
    int k = 3;

    int i = 0;
    int j = sizeof(a)/sizeof(int) - 1;
    
    while(i < j) {
        int csum = a[i] + a[j];
        if (csum < k) { i++; }
        else if (csum > k) { j--; }
        else if (csum == k) {
            cout << a[i] << " and " << a[j] << endl; 
            i++;
            j--;
        }
    }
    
    return 0;
}