// Check whether an array contains a subarray whose sum is 0 or not.

#include <iostream>
#include <unordered_set>

using namespace std;

bool checkSum(int arr[], int n) {
    unordered_set<int> s;

    int pre = 0;

    for (int i = 0; i < n; i++) {
        pre += arr[i];

        //before insertion check whether the sum is already present in the set or not
        if (pre == 0 or s.find(pre) != s.end()) {
            return true;
        }

        s.insert(pre);
    }

    return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (checkSum(arr, n)) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}