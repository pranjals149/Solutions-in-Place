class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int sum = 0;
        int totalSum = 0;
        int minSum = INT_MAX;
        int m = 0;

        int i = 0;
        int j = 0;
        int n = cardPoints.size();

        for (int i = 0; i < n; i++)
        {
            totalSum += cardPoints[i];
            sum += cardPoints[i];
            m++;

            if (m > n - k)
            {
                sum -= cardPoints[j];
                j++;
                m--;
            }

            if (m == n - k)
            {
                minSum = min(minSum, sum);
            }
        }

        return totalSum - minSum;
    }
};