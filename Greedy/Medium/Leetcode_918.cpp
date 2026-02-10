class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int curr_max = 0, curr_min = 0, max_sum = INT_MIN, min_sum = INT_MAX, total = 0;
        for(int i=0;i<nums.size();i++)
        {
            total += nums[i];

            curr_max = max(nums[i], curr_max+nums[i]);
            curr_min = min(nums[i], curr_min+nums[i]);

            max_sum = max(curr_max, max_sum);
            min_sum = min(curr_min, min_sum);
        }    
        if(max_sum < 0) return max_sum;
        return max(max_sum, total-min_sum);
    }
};
