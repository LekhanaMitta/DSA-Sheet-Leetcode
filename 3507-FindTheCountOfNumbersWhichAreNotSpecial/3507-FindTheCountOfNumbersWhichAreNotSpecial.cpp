// Last updated: 2/9/2026, 1:26:39 PM
class Solution {
public:
    int nonSpecialCount(int l, int r) 
    {
        int left = sqrt(l), right = sqrt(r);
        int n = r - l + 1;
        if(left * left != l)    left++;
        vector<bool> dp(right+1, true);
        dp[0] = false, dp[1] = false;
        for(int i=2;i<=right;i++)
        {
            if(dp[i])
                for(int j=i*i;j<=right;j+=i)
                    dp[j] = false;
        }
        int cnt = 0;
        for(int i=left;i<=right;i++)   
            if(dp[i])   cnt++;
        return n - cnt;

    }
};