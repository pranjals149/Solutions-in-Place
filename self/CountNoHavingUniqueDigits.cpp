// Write a program to find the count of numbers that consists of unique digits.

// Input:
// Input consists of two Integer lower and upper value of a range

// Output:
// The output consists of a single line, print the count of unique digits in a given range. Else Print"No Unique Number"

// Input -
// 10
// 15

// Output
// 5

#include <iostream>
#include <unordered_map>

using namespace std;

int solve(int l, int r)
{
    int ans = 0;

    for (int i = l; i <= r; i++)
    {
        int num = i;
        unordered_map<int, bool> m;

        while (num > 0)
        {
            if (m[num % 10])
            {
                break;
            }

            m[num % 10] = true;
            num = num / 10;
        }

        if (num == 0)
        {
            ans++;
        }
    }

    return ans;
}

int main()
{
    int l, r;
    cin >> l;
    cin >> r;

    cout << solve(l, r) << endl;

    return 0;
}