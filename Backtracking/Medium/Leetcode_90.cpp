class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int>> subs;
        int n =  nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<(1 << n);i++)
        {
            vector<int> temp = {};
            for(int j=0;j<n;j++)
            {
                if(i & (1 << j))
                    temp.push_back(nums[j]);
            }
            subs.insert(temp);
        }    
        vector<vector<int>> sub;
        for(vector<int> s : subs)
            sub.push_back(s);
        return sub;
    }
};
