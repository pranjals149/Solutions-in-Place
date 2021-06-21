#include <iostream>
#include <unordered_map>
#include <cstring>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxVowels(string s, int k)
    {
        queue<int> q;
        int cnt = 0;
        int max_so_far = 0;

        for (int i = 0; i < s.length(); i++)
        {
            q.push(s[i]);

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                cnt++;

            if (q.size() == k)
            {
                max_so_far = max(max_so_far, cnt);

                char c = q.front();

                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    cnt--;
                q.pop();
            }
        }

        return max_so_far;
    }
};