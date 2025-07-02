class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int cnt = 0, j=0;
        for(int i=0;i<t.length();i++)
            if(t[i] == s[j] && j < s.length())
                j++, cnt++;
        return (cnt == s.length());  
    }
};
