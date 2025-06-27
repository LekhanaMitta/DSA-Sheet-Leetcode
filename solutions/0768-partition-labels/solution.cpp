class Solution {
public:
    vector<int> merge_interval(vector<pair<int, int>> &vec)
    {
        sort(vec.begin(), vec.end());
        int a = vec[0].first;
        int b = vec[0].second;
        // cout << a << " " << b << endl;
        vector<int> ans;
        for(int i=1;i<vec.size();i++)
        {
            // cout << vec[i].first << " " << vec[i].second << endl;
            if(vec[i].first <= b)
                b = max(b, vec[i].second);
            else
            {
                // cout << b << " " << a << endl;
                ans.push_back(b-a+1);
                a = vec[i].first;
                b = vec[i].second;
            }
            // cout << "a and b values: " <<  a << " " << b << endl;
        }
        ans.push_back(b-a+1);
        return ans;
    }
    vector<int> partitionLabels(string s) 
    {
        map<char, pair<int, int>>m;
        for(int i=0;i<s.length();i++)
        {
            if(!m[s[i]].first)
            {
                m[s[i]].first = i+1;
                m[s[i]].second = i+1;
            }
            else
                m[s[i]].second = i+1;
        }
        vector<pair<int, int>> vec;
        for(auto [key, value]:m)
        {
            // cout << key << " " << value.first << " " << value.second << endl;
            vec.push_back(make_pair(value.first, value.second));
        }
        // cout << vec.size() << endl;
        return merge_interval(vec);
    }
};
