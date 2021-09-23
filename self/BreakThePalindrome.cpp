#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.size() == 1)
        {
            return "";
        }
        int i = 0, j = palindrome.size() - 1;

        while (i < j)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }

            i++;
            j--;
        }

        palindrome[palindrome.size() - 1] = 'b';
        return palindrome;
    }
};