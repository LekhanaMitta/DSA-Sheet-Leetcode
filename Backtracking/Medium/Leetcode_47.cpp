class Solution {
public:
    void perms(vector<int> &nums, set<vector<int>> &sperm, int idx)
    {
        if(idx == nums.size())
        {
            sperm.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i], nums[idx]);
            perms(nums, sperm, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        set<vector<int>> sperm;
        perms(nums, sperm, 0);
        vector<vector<int>> res;
        for(vector<int> s : sperm)
            res.push_back(s);
        return res;    
    }
};
