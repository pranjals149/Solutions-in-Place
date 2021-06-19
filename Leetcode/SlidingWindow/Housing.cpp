// Along one side of a road there is a sequence of vacant plots of land. Each plot has a different area (non-zero). So, the areas form a sequence A[1], A[2], ... A[N].

// You want to buy K acres of land to build a house. You want to find all segments of contiguous plots (a subsection in the sequence) of whose sum is exactly K.

// Sliding Window

#include <iostream>

using namespace std;

void housing(int *arr, int n, int k)
{

    int i = 0;
    int j = 0;
    int cs = 0;

    while (j < n)
    {

        //expanding to right
        cs += arr[j];
        j++;

        //rremove elements from the left till the current sum > sum and i < j
        while (cs > k and i < j)
        {
            cs = cs - arr[i];
            i++;
        }

        //check if any given point your cs == k
        if (cs == k)
        {
            //print that window
            cout << i << " - " << j - 1 << endl;
        }
    }

    return;
}

int main()
{
    int plots[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plots) / sizeof(int);
    int k = 8;

    housing(plots, n, k);

    return 0;
}