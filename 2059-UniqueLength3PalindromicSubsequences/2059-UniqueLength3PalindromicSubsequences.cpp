// Last updated: 2/9/2026, 1:26:49 PM
class Solution {
public:
    // set<string> st;
    // void genSubseq(string s, int i, string curr, int k)
    // {
    //     if(curr.length() == k && curr[0] == curr[2])
    //     {
    //         st.insert(curr);
    //         return;
    //     }
    //     if(i == s.length() || curr.length() > k)    return;
    //     curr.push_back(s[i]);
    //     genSubseq(s, i+1, curr, k);
    //     curr.pop_back();
    //     genSubseq(s, i+1, curr, k);
    // }
    int countPalindromicSubsequence(string s) 
    {
        // genSubseq(s, 0, "",3);
        // return st.size();

        map<char, pair<int,int>> m;
        int ans = 0;
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i]) == m.end())
                m[s[i]].first = i;
            else
                m[s[i]].second = i;
        }
        for(auto it = m.begin();it!=m.end();it++)
        {
            vector<bool> found(26,false);
            int first = it->second.first;
            int last = it->second.second;
            for(int i=first+1;i<last;i++)
                found[s[i]-'a'] = true;
            for(int i=0;i<found.size();i++)
            {
                if(found[i]) ans++;
            }
        }
        return ans;
    }
};