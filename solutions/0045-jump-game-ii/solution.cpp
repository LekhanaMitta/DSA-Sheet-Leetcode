class Solution {
public:
    int jump(vector<int>& nums)
    {
        if(nums.size() <= 1)    return 0;
        int steps = 0, maxReach = 0, end = 0;
        for(int i=0;i<nums.size();i++)
        {
            // if(maxReach >= nums.size()-1)   return steps;
            // if(maxReach < i+nums[i])
            // {
            //     steps++;
            //     maxReach = nums[i]+i;
                    
            // }
            maxReach = max(maxReach, nums[i] + i);
            if(i == end)
            {
                steps++;
                end = maxReach;
                if(end >= nums.size()-1)
                    return steps;
            }
        }  
        return steps;
    }
};
