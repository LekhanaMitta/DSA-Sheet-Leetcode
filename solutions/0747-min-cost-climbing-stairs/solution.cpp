class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        if(cost.size() == 2)    return min(cost[0], cost[1]); 
        int n = cost.size();  
        vector<int> dp(n+1, 0);
        dp[0] = 0, dp[1] = 0, dp[2] = min(cost[0], cost[1]);
        for(int i = 3;i<=cost.size();i++)
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        // cout << dp[0] << " " << dp[1] << " " << dp[2] << " " << dp[3];
        return dp[n];
    }
};
// 10  15  20
// 10  10  15
        
//         1   100 1   1   1   100 1   1   100 1
// dp  0   1   1   2   2   3   3   4   5   5   6

// dp[0] = 0
// dp[1] = a[0]
// dp[2] = min(a[1], dp[0]+a[0])
// dp[i+1] = min(dp[i])
// dp[i] = 
// min(dp[i], dp[i-1]+cost[i])
