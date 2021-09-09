#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ceiling(int target, vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (target < arr[mid])
        {
            e = mid - 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return arr[s];
}

int main()
{
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << ceiling(target, arr, n);

    return 0;
}