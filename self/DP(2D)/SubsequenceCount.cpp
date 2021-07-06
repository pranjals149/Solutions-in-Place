// Given two strings, find the number of times the second string occurs as a subsequence in the first string.

// Input
// s1 = "ABCDCE"
// s2 = "ABC"

// Output
// 2

#include <iostream>

using namespace std;

//Recursive code
int countSub(string a, string b, int m, int n)
{
    //base case
    if (m == -1 and n == -1 or n == -1)
    {
        return 1;
    }
    else if (m == -1)
    {
        return 0;
    }

    //recursive call
    if (a[m] == b[n])
    {
        return countSub(a, b, m - 1, n - 1) + countSub(a, b, m - 1, n);
    }

    return countSub(a, b, m - 1, n);
}

int main()
{
    string a = "ABCECDG";
    string b = "ABC";

    cout << countSub(a, b, a.size() - 1, b.size() - 1) << endl;

    return 0;
}