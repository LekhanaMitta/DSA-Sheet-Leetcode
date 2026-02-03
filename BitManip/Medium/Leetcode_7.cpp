class Solution {
public:
    int reverse(int x) 
    {
        long long ans = 0;     // Stores reversed number (long long to detect overflow)
        bool sign = true;      // true → positive, false → negative

        // Edge case: reversing INT_MAX or INT_MIN would overflow
        if (x == INT_MAX || x == INT_MIN)
            return 0;

        // Handle negative numbers
        if (x < 0)
        {
            sign = false;      // Remember that the original number was negative
            x = 0 - x;         // Convert x to positive for easier digit reversal
        }

        // Reverse the digits of x
        while (x)
        {
            // Shift previously reversed digits to the left
            ans *= 10;

            // Append the last digit of x
            ans += x % 10;

            // Remove the last digit from x
            x /= 10;
        }

        // If original number was positive
        if (sign)
        {
            // Check overflow against INT_MAX (2^31 - 1)
            if (ans > 2147483647)
                return 0;
            return ans;
        }
        // If original number was negative
        else
        {
            // Check overflow against absolute INT_MIN (2^31)
            if (ans > 2147483648)
                return 0;
            return -ans;
        }
    }
};
