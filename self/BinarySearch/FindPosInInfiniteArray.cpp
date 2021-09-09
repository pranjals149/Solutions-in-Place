#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int> &arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (target < arr[mid])
        {
            end = mid - 1;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return arr[start];
}

int findingRange(vector<int> &arr, int target)
{
    //fisrt find the range
    int start = 0;
    int end = 1;

    //condition for the target to lie in the range
    while (target > arr[end])
    {
        int newStart = end + 1;
        //double the box value
        //new end = previous end + sozeofbox*2
        end = end + (end - start + 1) * 2;
        start = newStart;
    }

    return binarySearch(arr, target, start, end);
}

// Driver program
int main()
{
    vector<int> arr = {3, 5, 7, 9, 10, 90, 100, 130,
                       140, 160, 170};

    cout << findingRange(arr, 10) << endl;

    return 0;
}
