// Last updated: 2/9/2026, 1:27:18 PM
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        vector<bool> ans;
        int num = 0;
        for(int i=0;i<nums.size();i++)
        {
            num = (num * 2 + nums[i]) % 5;
            ans.push_back(num % 5 == 0);
        }
        return ans;
    }
};