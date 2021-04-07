//Also known as Activity selection problem

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    // Fist value is start time and second value is end time
    return p1.second < p2.second;
}

int main()
{
    int t, n, s, e;

    cin >> t;

    while (t--)
    {
        vector<pair<int, int>> v;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }

        //Activity selection algorithm
        // Sort all Activity
        sort(v.begin(), v.end(), compare);

        //start picking activities
        int res = 1;
        int fin = v[0].second;

        //iterate over remaining activiites
        for (int i = 1; i < n; i++)
        {
            if (v[i].first >= fin)
            {
                fin = v[i].second;
                res++;
            }
        }
        cout << res << endl;

        v.clear();
    }

    return 0;
}