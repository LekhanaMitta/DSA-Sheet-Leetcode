class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<long long> dp(n+1);
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for(int i=1;i<=n;i++)
        {
            long long ugly2 = 2*dp[i2];
            long long ugly3 = 3*dp[i3];
            long long ugly5 = 5*dp[i5];
            long long ugly = min(ugly2, min(ugly3, ugly5));
            dp[i] = ugly;
            if(ugly == ugly2)   i2++;
            if(ugly == ugly3)   i3++;
            if(ugly == ugly5)   i5++;
        }    
        return dp[n-1];
    }
};
