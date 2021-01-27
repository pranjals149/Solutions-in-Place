#include <iostream>
#include <algorithm>

using namespace std;

void targetSum(int *arr, int n, int target)
{
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            cout << arr[left] << " and " << arr[right] << endl;
            left++;
            right--;
        }
    }
}

int main()
{
    int n, a[100], m;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;

    targetSum(a, n, m);
    return 0;
}