class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int curr_sum = 0, max_sum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum = max(nums[i], nums[i]+curr_sum);
            max_sum = max(curr_sum, max_sum);
        }    
        return max_sum;
    }
};
/*
For every i:
Maximum subarray sum ending at current index
Maximum subarray sum seen so far
*/
