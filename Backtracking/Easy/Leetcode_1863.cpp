class Solution {
public: 
    // int dfs(vector<int> &nums, int idx, int xo)
    // {
    //     if(idx == nums.size())
    //         return xo;
    //     int include = dfs(nums, idx+1, xo ^ nums[idx]);
    //     int exclude = dfs(nums, idx+1, xo);
    //     return exclude + include;
    // }
    int subsetXORSum(vector<int>& nums) 
    {
        // return dfs(nums, 0, 0); 
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<(1 << n);i++)
        {
            int xo = 0;
            for(int j=0;j<n;j++)
            {
                if(i & (1 << j))
                    xo ^= nums[j];
            }
            sum += xo;
        }   
        return sum;
    }
};
