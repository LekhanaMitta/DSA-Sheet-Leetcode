class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX-1);
        // state: dp[i] -> minimum jumps needed to reach ith step from 0 index.
        dp[0] = 0;
        for(int i=0;i<n;i++)    
        {
            if(nums[i] == 0)
                continue;
            for(int j=1;j<=nums[i];j++)
            {
                dp[min(i+j, n-1)] = min(dp[i]+1, dp[min(i+j, n-1)]);
            }
            cout << dp[i] << " ";
        }
        return dp[n-1];
    }
};
