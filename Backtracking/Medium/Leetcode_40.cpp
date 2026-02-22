class Solution {
public:
        void backtrack(vector<int> &candidates, set<vector<int>> &res, vector<int>&comb, int target, int sum, int idx)
    {
        if(sum >= target)
        {
            if(sum == target)
                res.insert(comb);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target)  break;
            comb.push_back(candidates[i]);
            backtrack(candidates, res, comb, target, sum+candidates[i], i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        set<vector<int>> res;
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, comb, target, 0, 0);
        for(vector<int> s : res)
            ans.push_back(s);
        // sort(ans.begin(), ans.end());
        return ans;    
    }
};
