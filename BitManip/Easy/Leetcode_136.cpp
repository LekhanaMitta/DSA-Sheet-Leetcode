class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int xo = nums[0];
        for(int i=1;i<nums.size();i++)    
            xo ^= nums[i];
        return xo;
    }
};
/*
Special Property of XOR :
x ^ x = 0
x ^ 0 = x
*/
