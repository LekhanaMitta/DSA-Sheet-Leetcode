class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        // stack<char> st;
        // string ans = "";
        // int cnt = 0;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i] == '(')
        //     {
        //         st.push(s[i]);
        //         cnt++;
        //     }
        //     else if(s[i] == ')')
        //     {
        //         st.push(s[i]);
        //         cnt--;
        //     }
        //     if(cnt == 0)
        //     {
        //         st.pop();
        //         string str = "";
        //         while(!st.empty())
        //         {
        //             str += st.top();
        //             st.pop();
        //         }
        //         str.pop_back();
        //         reverse(str.begin(), str.end());
        //         ans += str;
        //         cout << str << endl;
        //     }
        // } 
        // return ans; 
        int cnt = 0;
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                cnt++;
                if(cnt > 1)
                    ans += s[i];
            }
            else
            {
                cnt--;
                if(cnt >= 1)
                    ans += s[i];
            }
        }  
        return ans;
    }
};
