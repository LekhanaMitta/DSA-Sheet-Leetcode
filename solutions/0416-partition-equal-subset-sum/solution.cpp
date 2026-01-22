class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2 == 1)    return 0;
        int t = sum/2;
        vector<bool> dp(t+1,false);
        dp[0] = true;
        for(int i=0;i<n;i++)
        {
            for(int j=t;j>=nums[i];j--)
            {
                dp[j] = dp[j-nums[i]] || dp[j];
                // cout << dp[j] << " ";
            }
            // cout << endl;
        }    
        return dp[t];
    }
};
