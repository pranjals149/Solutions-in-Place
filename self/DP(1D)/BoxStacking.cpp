// We are given an array of boxes. Each boxes is represented using 3 integers denoting height, width, depth of the box. Our goal is stack up the boxes and maximise the total height of the stack.

// You cant rotate any box, i.e. integers in each box must represent [width, depth, height] at all times.

// A box must have strictly smaller width, depth, and heoght than any other box below it.

// Input
// Boxes = [
//     [2, 1, 2],
//     [3, 2, 3],
//     [2, 2, 8],
//     [2, 3, 4],
//     [2, 2 , 1],
//     [4, 4, 5]
// ]

// Output
// 10

// Explaination: We can stack 3 boxes to get height 10.
// [2, 1, 2],
// [3, 2, 3]
// [4, 4, 5]

#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2)
{
    return b1[2] > b2[2];
}

bool canPlace(vector<int> b1, vector<int> b2)
{
    if (b1[0] > b2[0] and b1[1] > b2[1] and b1[2] > b2[2])
    {
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> boxes)
{
    //Sorting
    sort(boxes.begin(), boxes.end(), compareBoxes);

    int n = boxes.size();

    //DP
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        dp[i] = boxes[i][2];
    }

    // we will start from 2nd box since 1st box cannot be stacked
    for (int i = 1; i < n; i++)
    {
        //check for all boxes whose index is less than i
        for (int j = 0; j < i; j++)
        {
            if (canPlace(boxes[j], boxes[i]))
            {
                int curr_height = boxes[i][2];

                if (dp[j] + curr_height > dp[i])
                {
                    dp[i] = dp[j] + curr_height;
                }
            }
        }
    }

    int max_height = 0;

    for (int i = 0; i < n; i++)
    {
        max_height = max(max_height, dp[i]);
    }

    return max_height;
}

int main()
{
    vector<vector<int>> boxes = {
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5}};

    int height = boxStacking(boxes);

    return 0;
}