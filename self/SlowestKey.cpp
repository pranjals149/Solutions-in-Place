#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        char ans = keysPressed[0];
        int time = releaseTimes[0];

        for (int i = 1; i < keysPressed.size(); i++)
        {
            int curr_time = releaseTimes[i] - releaseTimes[i - 1];

            if (curr_time >= time)
            {
                if (curr_time > time)
                {
                    time = curr_time;
                    ans = keysPressed[i];
                }
                else
                {
                    ans = max(ans, keysPressed[i]);
                }
            }
        }

        return ans;
    }
};