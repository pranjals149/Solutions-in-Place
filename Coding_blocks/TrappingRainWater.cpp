#include <iostream>

using namespace std;

int rainWater(int height[], int n)
{
    int lmax = 0, rmax = 0, ans = 0;

    int i = 0;
    int j = n - 1;

    while (i <= j)
    {
        if (height[i] <= height[j])
        {
            if (height[i] < lmax)
            {
                ans += (lmax - height[i]);
            }
            else
            {
                lmax = height[i];
            }
            i++;
        }
        else
        {
            if (height[j] <= rmax)
            {
                ans += (rmax - height[j]);
            }
            else
            {
                rmax = height[j];
            }
            j--;
        }
    }

    return ans;
}

int main()
{
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(height) / sizeof(int);

    cout << rainWater(height, n) << endl;

    return 0;
}