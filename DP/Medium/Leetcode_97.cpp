class Solution {
public:
/*
1. State : dp[i][j] = true if s3[0 .. i+j-1] can be formed
          using s1[0 .. i-1] and s2[0 .. j-1]
2. Transition : 
Option A: last came from s1
Then previously we were at (i-1, j)
And current char must match: s1[i-1] == s3[i+j-1]

Option B: last came from s2
Then previously we were at (i, j-1)
And current char must match: s2[j-1] == s3[i+j-1]

dp[i][j] = (dp[i-1][j] AND s1[i-1] == s3[i+j-1]) OR (dp[i][j-1] AND s2[j-1] == s3[i+j-1])

Base case :
dp[0][0] = true
dp[0][j] = dp[0][j-1] AND s2[j-1] == s3[j-1]
dp[i][0] = dp[i-1][0] AND s1[i-1] == s3[i-1]

Answer : dp[n][m]
*/
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n = s1.length(), m = s2.length();
        if(s3.length() != n+m)    return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for(int i=1;i<=n;i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int j=1;j<=m;j++)
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int k = i+j;
                dp[i][j] = (s1[i-1] == s3[k-1] && dp[i-1][j]) || (s2[j-1] == s3[k-1] && dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
