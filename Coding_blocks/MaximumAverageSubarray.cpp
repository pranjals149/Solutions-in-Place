class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i = 0;
        double avg = INT_MIN;
        double sum = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];

            if (j >= k - 1)
            {
                if (sum / k > avg)
                {
                    avg = sum / k;
                }

                sum = sum - nums[i];
                i++;
            }
        }

        return avg;
    }
};