class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        int cnt = 1, n = s.length();
        stack<pair<char,int>> st;
        st.push({s[n-1],1});
        cout << s[n-1] << " --> " << cnt << endl;
        for(int i=s.length()-2;i>=0;i--)
        {
            if(!st.empty() && st.top().first == s[i])   cnt++;
            else    cnt = 1;
            cout << s[i] << " --> " << cnt << endl;
            st.push({s[i],cnt});
            if(cnt == k)
            {
                while(!st.empty() && cnt > 0)
                {
                    st.pop();
                    cnt--;
                }
                if(!st.empty()) cnt = st.top().second;
                else    cnt = 1;
            }
        }  
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }  
        return ans;
    }
};
