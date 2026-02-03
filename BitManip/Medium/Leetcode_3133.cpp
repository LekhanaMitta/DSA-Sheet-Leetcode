class Solution {
public:
    long long minEnd(int n, int x) 
    {
        long long ans = x;                 // Start from x
        long long m = (long long)n - 1;    // Number of increments needed

        for (int i = 0; m > 0; i++)
        {
            // If the ith bit of ans is currently unset (0)
            if ((ans & (1LL << i)) == 0)
            {
                // Copy the lowest bit of m into this position
                ans |= (m & 1LL) << i;

                // Move to the next bit of m
                m >>= 1;
            }
        }
        return ans;
    }
};
