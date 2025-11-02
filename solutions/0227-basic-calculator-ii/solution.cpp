class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st, st1;
        map<char, int> m;
        m['+'] = 1, m['-'] = 1;
        m['*'] = 2, m['/'] = 2;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ') continue;
            else if(s[i] >= '0' && s[i] <= '9')
            {
                int num = 0;
                while(s[i] >= '0' && s[i] <= '9')
                {
                    num *= 10;
                    num += s[i] - '0';
                    i++;
                }
                st.push(num);
                i--;
                cout << num << " ";
            }
            else
            {
                while(!st1.empty() && m[st1.top()] >= m[s[i]])
                {
                    char c = st1.top();
                    st1.pop();
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    cout << a << " " << b << " " << c << endl;
                    if(c == '+')    st.push(b + a);
                    else if(c == '-')   st.push(b - a);
                    else if(c == '*')   st.push(b * a);
                    else if(c == '/')   st.push(b / a);
                }
                st1.push(s[i]);
            }
        }   
        while(!st1.empty())
                {
                    char c = st1.top();
                    st1.pop();
                    int a = st.top(); st.pop();
                    int b = st.top(); st.pop();
                    // cout << a << " " << b;
                    if(c == '+')    st.push(b + a);
                    else if(c == '-')   st.push(b - a);
                    else if(c == '*')   st.push(b * a);
                    else if(c == '/')   st.push(b / a);
                }
            
        return st.top();
    }
};
