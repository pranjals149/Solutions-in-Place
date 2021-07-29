class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int quotient = 0;
        bool minus = (dividend > 0 and divisor < 0) || (dividend < 0 and divisor > 0);

        if (dividend > 0)
        {
            dividend = -dividend;
        }
        if (divisor > 0)
        {
            divisor = -divisor;
        }

        while (dividend <= divisor)
        {
            dividend = dividend - divisor;
            quotient = quotient - 1;
        }

        if (minus)
        {
            return quotient;
        }

        if (quotient == INT_MIN)
        {
            return INT_MAX;
        }

        return -quotient;
    }
};