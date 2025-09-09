class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        long long n = questions.size();
        vector<long long> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1;i>=0;i--)
        {
            long long p_i = questions[i][0];
            long long b_i = questions[i][1];
            dp[i] = max(dp[i+1], p_i + dp[min(i+b_i+1, n)]);
        }    
        return dp[0];
    }
};
