class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        map<char, int> m;
        vector<pair<int,int>> parts;
        int start = 0, end = 0;
        for(int i=0;i<s.length();i++)
            m[s[i]] = i;
        for(int i=0;i<s.length();i++)
        {
            end = max(end, m[s[i]]);
            if(i == end)
            {
                parts.push_back({start, end});
                start = i+1;
            }
        }    
        vector<int> ans;
        for(int i=0;i<parts.size();i++)
        {
            ans.push_back(parts[i].second-parts[i].first+1);
        }
        return ans;
    }
};
