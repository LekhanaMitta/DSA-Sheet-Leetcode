class Solution {
public:
    int countHousePlacements(int n) 
    {
        if(n == 1)  return 4;
        int mod = 1000000007;
        // vector<long long> dp(n+1,0);
        // dp[1] = 2, dp[2] = 3;
        // for(int i=3;i<=n;i++)
        //     dp[i] = (dp[i-1]%mod+dp[i-2]%mod)%mod;
        // long long ans = ((dp[n]%mod)*(dp[n]%mod))%mod;
        // return ans;
        long long before_last = 2, last = 3, ans;
        for(int i=3;i<=n;i++)
        {
            long long ans = last + before_last;
            before_last = last % mod;
            last = ans % mod;
        }
        ans = last;
        return (ans * ans) % mod;
    }
};
