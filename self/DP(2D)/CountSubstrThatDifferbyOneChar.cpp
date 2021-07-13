#include <iostream>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int diff = 0;

                if (s[i] != t[j])
                {
                    ans++;
                    diff++;
                }

                int x = i + 1;
                int y = j + 1;

                while (x < n and y < m)
                {
                    if (s[x] != t[y])
                    {
                        diff++;

                        if (diff > 1)
                        {
                            break;
                        }
                        else
                        {
                            ans++;
                        }
                    }
                    else
                    {
                        if (diff == 1)
                        {
                            ans++;
                        }
                    }
                    x++;
                    y++;
                }
            }
        }

        return ans;
    }
};