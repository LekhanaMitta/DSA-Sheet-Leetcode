class Solution {
public:
    int countPrimes(int n) 
    {
        if(n == 0 || n == 1 || n == 2)  return 0;
        vector<bool> dp(n, true);
        dp[0] = false, dp[1] = false;
        for(int i=2;i*i<n;i++)   
        {
            if(dp[i])
            {
                for(int j=i*i;j<n;j+=i)
                    dp[j] = false;
            }
        }
        int cnt = 0;
        for(int i = 2;i<dp.size();i++)
            if(dp[i])   cnt++;
        return cnt;
    }
};
