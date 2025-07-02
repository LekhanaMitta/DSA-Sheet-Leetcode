class Solution {
public:
    vector<int> countBits(int n) 
    {
        if(n == 0)  return {0};
        if(n == 1)    return {0, 1};
        vector<int> dp(n+1, 1);
        dp[0] = 0, dp[1] = 1;
        for(int i = 2;i <= n;i++)
        {
            int root = log2(i);
            int power = pow(2, root);
            dp[i] = dp[power] + dp[i-power];
        }
        return dp;
    }
};

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 0 1 1 2 1 2 2 3 1 2 2   3  2  3  3  
