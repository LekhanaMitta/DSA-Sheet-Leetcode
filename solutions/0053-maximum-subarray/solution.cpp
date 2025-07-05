class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> ans;
        int curr_max = nums[0], overall_max = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr_max = max(nums[i], curr_max + nums[i]);
            overall_max = max(curr_max, overall_max);
        } 
        return overall_max;
    }
};
