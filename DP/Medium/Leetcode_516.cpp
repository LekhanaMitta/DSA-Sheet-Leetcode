class Solution {
public:
/*
State : dp[i][j] --> Length of palindrome sequence in substring s[i...j]
Transition : 
i. If s[i] == s[j] then dp[i][j] = 2 + dp[i+1][j-1]
ii. else dp[i][j] = max(d[i+1][j], dp[i][j-1])
Base case: dp[i][i] = 1
Answer : dp[0][n-1]
*/
    int longestPalindromeSubseq(string s) 
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        for(int len = 2;len <= n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j = i + len -1;
                if(s[i] == s[j])
                    dp[i][j] = 2 + ((i+1 <= j-1) ? dp[i+1][j-1] : 0);
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
