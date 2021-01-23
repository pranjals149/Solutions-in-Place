#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        //using tortorise method

        int slow = nums[0]; //place slow & fast pointer at 0th index
        int fast = nums[0];

        // move slow by 1 & fast by 2 step till they collide

        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        //place fast at starting point

        fast = nums[0];

        //move slow & fast by 1 step till they collide

        while (slow != fast)
        {

            slow = nums[slow];
            fast = nums[fast];
        }

        //colliding point is the duplicate number

        return slow;
    }
};