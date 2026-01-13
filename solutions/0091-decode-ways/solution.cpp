class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.length();
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;
        for(int i=1;i<n;i++)
        {
            // Include previous character 
            dp[i+1] += (s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')) ? dp[i-1] : 0;
            // Don't include previous character
            dp[i+1] += (s[i] >= '1' && s[i] <= '9') ? dp[i] : 0;
        }   
        return dp[n]; 
    }
};
