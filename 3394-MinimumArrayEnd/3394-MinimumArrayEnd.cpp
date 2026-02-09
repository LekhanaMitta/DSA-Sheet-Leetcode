// Last updated: 2/9/2026, 1:26:41 PM
class Solution {
public:
    long long minEnd(int n, int x) 
    {
        long long ans = x;
        long long m = (long long)n-1;
        for(int bit = 0; m>0;bit++)
        {
            if((ans & (1LL<<bit)) == 0)
            {
                ans |= (m & 1LL) << bit;
                m >>= 1;
            }
        }    
        return ans;
    }
};