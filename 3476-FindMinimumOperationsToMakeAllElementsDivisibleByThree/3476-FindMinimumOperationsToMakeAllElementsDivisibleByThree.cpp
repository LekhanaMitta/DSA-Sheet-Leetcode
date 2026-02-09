// Last updated: 2/9/2026, 1:26:38 PM
class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int x = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] % 3 == 0)    continue;
            else    x++;
        }    
        return x;
    }
};