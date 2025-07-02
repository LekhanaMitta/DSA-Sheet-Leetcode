class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n == 0)  return {0};
        if(n == 1)    return {0, 1};
        vector<int> dp(n+1, 1);
        dp[0] = 0;
        for(int i = 2;i <= n;i++)
        {
            int root = log2(i);
            int power = pow(2, root);
            dp[i] = dp[power] + dp[i-power];
        }
        return dp;
    }
};
