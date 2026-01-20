class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> min_prod(n), max_prod(n);
        min_prod[0] = nums[0], max_prod[0] = nums[0];
        int mx = nums[0];
        for(int i=1;i<n;i++)
        {
            max_prod[i] = max(nums[i],max(nums[i]*min_prod[i-1], nums[i]*max_prod[i-1]));
            min_prod[i] = min(nums[i],min(nums[i]*min_prod[i-1], nums[i]*max_prod[i-1]));
            mx = max(mx, max_prod[i]);
        }    
        return mx;
    }
};
