class Solution {
public:
/*
1. Define the state : dp[i] --> no. of ways to reach ith step.
2. Transition(How do I reach this state?) : dp[i] = dp[i-1] + dp[i-2];
3. Base Case : dp[0] = 1, dp[1] = 1
4. Answer : dp[n]
*/
    int climbStairs(int n) 
    {
        // Solution - 1: T.C : O(n), S.C : O(n)
        // vector<int> dp(n+1,1);
        // for(int i=2;i<=n;i++)
        //     dp[i] = dp[i-1] + dp[i-2];
        // return dp[n];

        // Solution - 2: T.C : O(n), S.C : O(1)
        int first = 1, last = 1;
        if(n == 0 || n == 1)    return 1;
        for(int i=2;i<=n;i++)
        {
            int ans = first + last;
            first = last;
            last = ans;
        }
        return last;
    }
};
