class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int j = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(j>= 0 && j < i && nums[i])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }    
    }
};
