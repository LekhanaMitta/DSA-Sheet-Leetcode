class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        vector<pair<int, int>> freq(m.begin(), m.end());
        sort(freq.begin(), freq.end(), [](const pair<int, int> &x, const pair<int, int> &y){return x.second > y.second;});
        int i = 1;
        for(auto it:freq)
        {
            if(i <= k)
            {
                ans.push_back(it.first);
                i++;
            }
        }
        return ans;
    }
};
