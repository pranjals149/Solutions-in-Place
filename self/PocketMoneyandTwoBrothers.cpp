// Ram and Shyaam are two brothers who got monthly pocket money from their parents. Both receive some coins from their parents and the coin is represented by an integer value.

// Their parents have N coins. Your task is to distribute the coins between Ram and Shyam in a way such that the absolute difference between the total pocket money that Ram receives and the total pocket money that Shayam receives is minimised.

// You will be given an array of N coins which will represent integer value of each coin.

// Output the min absolute difference of their pocket money.

// Sample Input
// 5
// 1 2 3 4 5

// Sample Output
// 1

#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> v, int curr_idx, int total, int shyamSum)
{

    //Base case
    if (curr_idx == v.size())
    {
        return abs(total - 2 * shyamSum);
    }

    //include
    int c1 = solution(v, curr_idx + 1, total, shyamSum + v[curr_idx]);

    // exclude
    int c2 = solution(v, curr_idx + 1, total, shyamSum);

    return min(c1, c2);
}

int main()
{
    vector<int> v{1, 2, 3, 4, 5};
    int n = v.size();

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += v[i];
    }

    cout << solution(v, 0, total, 0) << endl;

    return 0;
}