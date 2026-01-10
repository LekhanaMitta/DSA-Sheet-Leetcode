class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1)  return nums[0];
        // vector<int> dp(n+1,0);
        // // Robbing 1st house and not robbing nth house(cost only until n-1 house)
        // dp[1] =  nums[0];
        // for(int i=2;i<n;i++)
        //     dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        // int x = dp[n-1]; // Maximum cost in method 1
        // // Not robbing 1st house and robbing nth house(dp[1] = 0)
        // dp[1] = 0;
        // for(int i=2;i<=n;i++)
        //     dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        // int y = dp[n];// maximum cost in method 2
        // // Compare cost through method 1 and method 2 return the max of it.
        // return max(x,y);
        int before_last = 0, last = nums[0];
        for(int i=1;i<n-1;i++)
        {
            int ans = max(before_last + nums[i], last);
            before_last = last;
            last = ans;
        }
        int x = last;
        before_last = 0, last = 0;
        for(int i=1;i<n;i++)
        {
            int ans = max(before_last + nums[i], last);
            before_last = last;
            last = ans;
        }
        int y = last;
        return max(x, y);    
    }
};
