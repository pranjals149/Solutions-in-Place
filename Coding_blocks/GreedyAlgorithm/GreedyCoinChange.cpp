#include <iostream>
#include <algorithm>

using namespace std;

int make_change(int *coins, int n, int money)
{
    int ans = 0;
    while (money > 0)
    {
        //upper_bound() is used to get the number greater than the given money
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        money = money - coins[idx];
        ans++;
    }

    return ans;
}

int main()
{
    int money;
    cin >> money;

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins) / sizeof(int);

    cout << "Coins Needed: " << make_change(coins, t, money) << endl;

    return 0;
}