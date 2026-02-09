class Solution {
    public int[] findErrorNums(int[] nums) 
    {
        int org = 0, dup = 0;
        for(int i=0;i<nums.length;i++)
        {
            int idx = Math.abs(nums[i])-1;
            if(nums[idx] < 0)    
                dup = Math.abs(nums[i]);
            else
                nums[idx] = -nums[idx];
        }    
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] > 0)
            {
                org = i+1;
                break;
            }
        }
        return new int[]{dup, org};
    }
}
