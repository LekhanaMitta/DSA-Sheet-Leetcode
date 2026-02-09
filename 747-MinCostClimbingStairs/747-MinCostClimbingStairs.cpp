// Last updated: 2/9/2026, 1:27:42 PM
class Solution {
public:
/*
State : dp[i] --> minimum cost to reach ith step.
Transition : To reach ith step we need to come from 
i. i-1 step ==> coming from i-1th step it costs cost[i-1]
ii. i-2 step ==> coming from i-2th step it costs cost[i-2]
- We choose which ever costs minimun so 
dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
Base case : dp[0] = 0, dp[1] = 0
Answer : dp[n]
*/
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        // vector<int> dp(n+1,0);
        // dp[1] = 0;
        // for(int i=2;i<=n;i++)
        //     dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        // return dp[n];    

        int older = 0, recent = 0;
        for(int i=2;i<=n;i++)
        {
            int ans = min(older+cost[i-2], recent+cost[i-1]);
            older = recent;
            recent = ans;
        }
        return recent;
    }
};