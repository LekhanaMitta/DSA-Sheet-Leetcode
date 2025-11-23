class Solution {
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        int total_sum = 0;
        int rem1_min1 = INT_MAX, rem1_min2 = INT_MAX;
        int rem2_min1 = INT_MAX, rem2_min2 = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            total_sum += nums[i]; 
            if(nums[i] % 3 == 1)
            {
                if(nums[i] < rem1_min1)
                {
                    rem1_min2 = rem1_min1;
                    rem1_min1 = nums[i];
                }
                else if(nums[i] < rem1_min2)
                    rem1_min2 = nums[i];
            }
            else if(nums[i] % 3 == 2)
            {
                if(nums[i] < rem2_min1)
                {
                    rem2_min2 = rem2_min1;
                    rem2_min1 = nums[i];
                }
                else if(nums[i] < rem2_min2)
                    rem2_min2 = nums[i];
            }
        }   
        if(total_sum % 3 == 0)  return total_sum;
        if(total_sum % 3 == 1)
        {
            int val = INT_MAX;
            val = min(val, rem1_min1);
            if(rem2_min2 != INT_MAX)
                val = min(val, rem2_min1 + rem2_min2);
            return (val == INT_MAX) ? 0 : total_sum - val;
        }
        else
        {
            int val = INT_MAX;
            val = min(val,rem2_min1);
            if(rem1_min2 != INT_MAX)
                val = min(val, rem1_min1 + rem1_min2);
            return (val == INT_MAX) ? 0 : total_sum - val;
        }
    }
};
