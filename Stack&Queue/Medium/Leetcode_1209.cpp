class Solution {
public:
    /*
    1. 
    */
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
            // Instead of pushing same element multiple times, just push elements once with it's frequency when this element is not same as top element. If frequency reaches k then don't add the element.
            st.push({s[i],cnt});
            if(cnt == k)
            {
                while(!st.empty() && cnt > 0)
                {
                    st.pop();
                    cnt--;
                }
                // You made the mistake here bro.
                // Always make sure if the stack is empty or not while accessing the top of the stack.
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
