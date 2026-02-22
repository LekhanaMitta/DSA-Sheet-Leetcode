class Solution {
public:
    void backtrack(vector<int> &candidates, set<vector<int>> &res, vector<int>&comb, int target, int sum, int idx)
    {
        if(sum >= target)
        {
            if(sum == target)   res.insert(comb);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            comb.push_back(candidates[i]);
            backtrack(candidates, res, comb, target, sum+candidates[i], i);
            backtrack(candidates, res, comb, target, sum+candidates[i], i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> comb;
        backtrack(candidates, res, comb, target, 0, 0);
        for(vector<int> s : res)
            ans.push_back(s);
        return ans;
    }
};
