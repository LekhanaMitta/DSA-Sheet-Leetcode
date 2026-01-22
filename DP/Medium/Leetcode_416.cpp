class Solution {
public:
/*
1. dp[t] = can we make sum t using numbers processed so far?
2. for each num:
  for t from target down to num:
      dp[t] = dp[t] OR dp[t - num]
3. dp[0] = true
4/ return dp[t]
*/
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
