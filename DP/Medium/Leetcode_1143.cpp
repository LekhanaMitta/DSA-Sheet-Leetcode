class Solution {
public:
/*
State : dp[i][j] --> length of common subseq from text1[0...i] and text2[0...j]
Transition : 
i. if(text1[i-1] == text2[j-1] ==> dp[i][j] = dp[i-1][j-1] + 1)
ii. else dp[i][j] = max(dp[i-1][j], dp[i][j-1])
Base Case:
dp[0][j] = 0, dp[i][0] = 0
Answer : dp[m][n]
*/
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }    
        return dp[m][n];
    }
};
