#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
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

        return -1;
    }

    int findPivot(vector<int> &arr)
    {
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            // 4 cases
            if (mid < end && arr[mid] > arr[mid + 1])
            {
                return mid;
            }

            if (mid > start && arr[mid] < arr[mid - 1])
            {
                return mid - 1;
            }

            if (arr[mid] <= arr[start])
            {
                end = mid - 1;
            }

            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int pivot = findPivot(nums);
        // if pivot is not found then array is not rotated
        if (pivot == -1)
        {
            // just normal Binary Search
            return binarySearch(nums, target, 0, nums.size() - 1);
        }

        // if pivot is found, then you found two asc sorted arrays
        // 3 cases
        if (nums[pivot] == target)
        {
            return pivot;
        }

        if (target >= nums[0])
        {
            return binarySearch(nums, target, 0, pivot - 1);
        }

        return binarySearch(nums, target, pivot + 1, nums.size() - 1);
    }
};

//for duplicate arrays
int findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        // 4 cases
        if (mid < end && arr[mid] > arr[mid + 1])
        {
            return mid;
        }

        if (mid > start && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }

        // if elements at middle, start, end are equal then just skip the duplicated
        if (arr[mid] == arr[start] && arr[mid] == arr[end])
        {
            //check if start is pivot
            if (arr[start] > arr[start + 1])
            {
                return start;
            }
            start++;

            //check whether end is pivot or not
            if (arr[end] < arr[end - 1])
            {
                return end - 1;
            }
            end--;
        }
        //left side is sorted so pivot should be in right side
        else if (arr[start] < arr[mid] || arr[start] == arr[mid] && arr[mid] > arr[end])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}