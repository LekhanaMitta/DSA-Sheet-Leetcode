class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        int first = nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        int second = max(nums[0], nums[1]);
        int third = 0;
        for(int i = 2; i<nums.size();i++)
        {
            third = max(first+nums[i], second);
            first = second;
            second = third;
        }
        return third;
    }
};
