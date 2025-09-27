class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1, false);
        // state: dp[i] -> is it possible to reach ith step from index 0
        // dp[0] = true;
        // for(int i=0;i<n;i++)
        // {
        //     if(!dp[i])
        //         return false;
        //     for(int j=1;j<=nums[i];j++)
        //         dp[min(i+j, n)] = dp[i];
        //     // cout << dp[i] << " ";
        // }    
        // return dp[n-1];
        int reach = 0;
        // Greedy: if any index i is not reachable from previous indices return false
        for(int i=0;i<n;i++)
        {
            if(i > reach)
                return false;
            reach = max(reach, i+nums[i]);
        }
        return true;

    }
};
