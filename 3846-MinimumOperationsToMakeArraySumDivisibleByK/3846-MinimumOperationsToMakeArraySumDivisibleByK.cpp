// Last updated: 2/9/2026, 1:26:36 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)  sum += nums[i];
        return sum - k * (sum/k);
    }
};