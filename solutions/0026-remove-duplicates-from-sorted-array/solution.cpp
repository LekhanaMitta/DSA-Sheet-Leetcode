class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int j = -1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] != nums[i+1])
            {
                j++;
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                // cout << temp;
            }
        } 
        nums[++j] = nums[nums.size()-1];
        // cout << j;   
        return j+1;
    }
};
