class Solution {
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int cnt = 0, max_cnt = 0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] == 0)
            {
                max_cnt = Math.max(cnt, max_cnt);
                cnt = 0;
            }
            else
                cnt++;
        }    
        return Math.max(max_cnt, cnt);
    }
}
