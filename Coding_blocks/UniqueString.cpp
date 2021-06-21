#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

string unique_substring(string str)
{
    int i = 0;
    int j = 0;

    int window_size = 0;
    int max_window_length = 0;
    int start_window = -1;

    unordered_map<char, int> m;

    while (j < str.length())
    {
        char ch = str[j];

        //if ch is inside hashmap and its index >= start of the current window
        //i denotes the start of the current window
        if (m.count(ch) and m[ch] >= i)
        {
            i = m[ch] + 1;
            window_size = (j - 1) - (i - 1); //updated remaining window lenght excluding current char
        }

        //update the last occurence
        m[ch] = j;
        window_size++;
        j++;

        //update max_window_length at every step
        if (window_size > max_window_length)
        {
            max_window_length = window_size;
            start_window = i;
        }
    }

    return str.substr(start_window, max_window_length);
}

int main()
{
    string input;
    cin >> input;

    cout << unique_substring(input);

    return 0;
}