class Solution {
public:
/*
1. dp[i] = length of the longest increasing subsequence ending at index i
2. dp[i] = max(dp[j] + 1) for all j < i where nums[j] < nums[i] else dp[i] = 1
3. dp[i] = 1  (for every i initially)
4. answer = max(dp[i]) for all i
*/
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
