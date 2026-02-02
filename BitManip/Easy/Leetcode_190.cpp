class Solution {
public:
    int reverseBits(int n) 
    {
        long long ans = 1, i=0;
        for(int i=0;i<32;i++)
        {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }    
        return ans;
    }
};
