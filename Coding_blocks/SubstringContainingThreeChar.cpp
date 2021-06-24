class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        vector<int> idx(3, -1);

        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            idx[s[i] - 'a'] = i;
            res += min(idx[0], min(idx[1], idx[2])) + 1;
        }

        return res;
    }
};