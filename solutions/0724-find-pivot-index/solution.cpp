class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int pre_sum = 0, n = nums.size()-1, post_sum = 0, sum = 0;
        for(int i=0;i<=n;i++)
            sum += nums[i];
        if(sum == nums[0])
            return 0;
        for(int i=1;i<=n-1;i++)   
        {
            pre_sum += nums[i-1];
            post_sum = sum - pre_sum - nums[i];
            // cout << pre_sum << " " << post_sum << endl;
            if(pre_sum == post_sum)
                return i;
        }
        if(sum == nums[n])
            return n;
        return -1;
    }
};
