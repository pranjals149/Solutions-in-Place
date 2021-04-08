#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int connectingWires(vector<int> a, vector<int> b)
{

    int ans = 0;
    vector<int> c;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); i++)
    {
        ans += abs(a[i] - b[i]);
    }

    return ans;
}

int main()
{
    vector<int> a{3, 4, 1};
    vector<int> b{2, 5, 1};
    cout << connectingWires(a, b) << endl;
    //return 0;
}
