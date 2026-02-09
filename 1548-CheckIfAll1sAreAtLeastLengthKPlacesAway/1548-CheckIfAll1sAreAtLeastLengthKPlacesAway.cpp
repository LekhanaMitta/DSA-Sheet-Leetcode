// Last updated: 2/9/2026, 1:26:56 PM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int num = -1e9;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                if(i - num <= k) return false;
                num = i;
            }
        }
        return true;
    }
};