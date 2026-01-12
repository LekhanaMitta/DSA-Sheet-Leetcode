class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.length();
        int start = 0, mx = 1;
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j = i+len-1;
                if(s[i] == s[j])
                {
                    if(len == 2)    dp[i][j] = 1;
                    else    dp[i][j] = dp[i+1][j-1];
                }
                else
                    dp[i][j] = 0;
                if(dp[i][j] && len > mx)
                {
                    mx = len;
                    start = i;
                }
            }
        }
        return s.substr(start, mx);
    }
};
