class Solution {
public:
    int func(int start, int end, vector<int> &nums)
    {
        int first = 0, second = 0, ans = 0;
        for(int i=start;i<=end;i++)
        {
            ans = max(second, first + nums[i]);
            first = second;
            second = ans;
        }
        return ans;
    }
    int rob(vector<int>& nums) 
    {
        // state : dp[i] - 
        int n = nums.size();
        if(n == 1)  return nums[0];
        // cout << func(0, n-2, nums) << " " << func(1, n-1, nums) << endl;
        return max(func(0, n-2, nums), func(1, n-1, nums));    
    }
};
