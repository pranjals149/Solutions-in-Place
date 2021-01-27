#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    vector<int> aArr;
    vector<int> bArr;

    int countApple = 0;
    int countOranges = 0;

    for (int i = 0; i < apples.size(); i++)
    {
        aArr.push_back(a);
    }
    for (int i = 0; i < oranges.size(); i++)
    {
        bArr.push_back(b);
    }

    vector<int> newArr1;
    vector<int> newArr2;

    for (int i = 0; i < aArr.size(); i++)
    {
        newArr1.push_back(aArr[i] + apples[i]);
    }
    for (int i = 0; i < bArr.size(); i++)
    {
        newArr2.push_back(bArr[i] + oranges[i]);
    }

    for (int i = 0; i < newArr1.size(); i++)
    {
        if (newArr1[i] <= t && newArr1[i] >= s)
        {
            countApple += 1;
        }
    }
    for (int i = 0; i < newArr2.size(); i++)
    {
        if (newArr2[i] <= t && newArr2[i] >= s)
        {
            countOranges += 1;
        }
    }

    cout << countApple << endl;
    cout << countOranges << endl;
}

int main()
{
    string st_temp;
    getline(cin, st_temp);

    vector<string> st = split_string(st_temp);

    int s = stoi(st[0]);

    int t = stoi(st[1]);

    string ab_temp;
    getline(cin, ab_temp);

    vector<string> ab = split_string(ab_temp);

    int a = stoi(ab[0]);

    int b = stoi(ab[1]);

    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string apples_temp_temp;
    getline(cin, apples_temp_temp);

    vector<string> apples_temp = split_string(apples_temp_temp);

    vector<int> apples(m);

    for (int i = 0; i < m; i++)
    {
        int apples_item = stoi(apples_temp[i]);

        apples[i] = apples_item;
    }

    string oranges_temp_temp;
    getline(cin, oranges_temp_temp);

    vector<string> oranges_temp = split_string(oranges_temp_temp);

    vector<int> oranges(n);

    for (int i = 0; i < n; i++)
    {
        int oranges_item = stoi(oranges_temp[i]);

        oranges[i] = oranges_item;
    }

    countApplesAndOranges(s, t, a, b, apples, oranges);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
