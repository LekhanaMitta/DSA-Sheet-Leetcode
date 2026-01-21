class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            int j = i-1, mx = INT_MIN;
            while(j >= 0)
            {
                if(nums[j] < nums[i])
                    mx = max(mx, dp[j]);
                j--;
            }
            if(mx != INT_MIN)   dp[i] = mx + 1;
            else    dp[i] = 1;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
