class Solution {
public:
    int countPartitions(vector<int>& nums) 
    {
        int total_sum = 0, left_sum = 0, right_sum = 0, cnt = 0;
        for(int i=0;i<nums.size();i++)  total_sum += nums[i];
        right_sum = total_sum;
        for(int i=0;i<nums.size()-1;i++)
        {
            left_sum += nums[i];
            right_sum -= nums[i];
            if(abs(left_sum - right_sum) % 2 == 0)  cnt++;
        } 
        return cnt;   
    }
};
