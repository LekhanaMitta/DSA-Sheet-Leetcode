// Last updated: 2/9/2026, 1:27:34 PM
class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        stack<char> st1, st2;
        for(int i=0;i<s.length();i++)
        {
            if(st1.empty() && s[i] == '#')   continue;
            else if(s[i] == '#')    st1.pop();
            else    st1.push(s[i]);
        }    
        for(int i=0;i<t.length();i++)
        {
            if(st2.empty() && t[i] == '#')   continue;
            else if(t[i] == '#')    st2.pop();
            else    st2.push(t[i]);
        }
        string s1 = "", s2 = "";
        if(st1.size() != st2.size())    return false;
        else
        {
            while(!st1.empty())
            {
                s1 += st1.top();
                st1.pop();
            }
            while(!st2.empty())
            {
                s2 += st2.top();
                st2.pop();
            }
        }
        return (s1 == s2);
    }
};