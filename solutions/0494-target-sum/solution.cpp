class Solution {
public:
int cnt = 0;
    void backtrack(vector<int> &nums, int sum, int i, int n, int target)
    {
        if(i == n)
        {
            if(sum == target)   cnt++;
            return;
        }
        backtrack(nums, sum - nums[i], i+1, n, target);
        backtrack(nums, sum + nums[i], i+1, n, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        backtrack(nums, 0, 0, nums.size(), target);
        return cnt;    
    }
};
