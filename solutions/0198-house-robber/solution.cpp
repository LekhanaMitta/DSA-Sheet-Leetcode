class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        // if(n == 1) return nums[0];
        // if(n == 2) return max(nums[0], nums[1]);
        // vector<int> dp(n+2, 0);
        // // state : dp[i] - max money I can get starting from ith house without alerting police
        // // recurrence: 
        // // i) skip current house - max amount = dp[i+1] 
        // // ii) rob current house - max amount = dp[i+2] + nums[i]
        // for(int i = n-1;i>=0;i--)
        //     dp[i] = max(dp[i+1], dp[i+2]+nums[i]);
        // return dp[0];   
        int first = 0, second = 0, ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            ans = max(first, second + nums[i]);
            second = first;
            first = ans;
        }
        return ans;
    }
};
