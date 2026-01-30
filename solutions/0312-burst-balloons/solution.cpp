class Solution {
public:
vector<vector<long long>> dp;
    int func(int start, int end, vector<int> &nums)
    {
        if(start > end) return 0;
        if(dp[start][end] != -1)    return dp[start][end];
        int mx = INT_MIN;
        for(int i = start; i<=end;i++)
        {
            int cost = nums[start-1]*nums[i]*nums[end+1] 
            + func(start, i-1, nums) 
            + func(i+1, end, nums);
            mx = max(mx, cost);
        }
        dp[start][end] = mx;
        return mx;
    }
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        dp.assign(n+2,vector<long long>(n+2,-1));
        return func(1, n, nums);
    }
};
