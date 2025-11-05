class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty())
            {
                char c = st.top();
                if((s[i] == ')' && c == '(') || (s[i] == '}' && c == '{') || (s[i] == ']' && c == '['))
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }    
        if(!st.empty())  return false;
        return true;
    }
};
