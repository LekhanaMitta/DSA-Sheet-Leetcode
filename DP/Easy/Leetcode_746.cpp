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
        return dp[n];
    }
};
