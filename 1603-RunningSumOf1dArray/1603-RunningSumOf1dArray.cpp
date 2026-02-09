// Last updated: 2/9/2026, 1:26:55 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        int temp = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            temp += nums[i];
            ans.push_back(temp);
        }    
        return ans;
    }
};