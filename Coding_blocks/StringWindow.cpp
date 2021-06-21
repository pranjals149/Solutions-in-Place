// Given two strngs, one big string and one small string, find the smallest window in the big string that contains all characters of the small string.

// Window can have additional characters than required.
// If small string has duplicates, then those duplicates must be present with same or higher count in window.

#include <iostream>
#include <unordered_map>
#include <cstring>
#include <climits>

using namespace std;

string stringWindow(string s, string p)
{
    //Array as a frequency map
    int fp[250] = {0}; // frequency of patterns
    int fs[256] = {0}; // frequency of string

    for (int i = 0; i < p.lenght(); i++)
    {
        fp[pat[i]]++;
    }

    // sliding window algo
    int cnt = 0;
    int start = 0;      // left contraction
    int start_idx = -1; // Start idx for best window
    int min_so_far = INT_MAX;
    int window_size;

    for (int i = 0; i < s.length; i++)
    {
        // expand the window by including current char
        char ch = s[i];
        fs[ch]++;

        //count how many characters have been matched till now (string and pattern)
        if (fp[ch] != 0 and fs[ch] <= fp[ch])
        {
            cnt += 1;
        }

        //keep a tract if all characters of the pattern are found in the current window then you can start contracting
        if (cnt == p.length())
        {
            // start contracting from the left to remove unwanted characters
            while (fp[s[start]] == 0 or fs[s[start]] > fp[s[start]])
            {
                fs[s[start]]--;
                start++;
            }

            // note the window size
            window_size = i - start + 1;

            if (window_size < min_so_far)
            {
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1)
        return "No window found";
    return s.substr(start_idx, min_so_far);
}

int main()
{
    string s, p;
    cin >> s >> p;

    cout << stringWindow(s, p) << endl;

    return 0;
}