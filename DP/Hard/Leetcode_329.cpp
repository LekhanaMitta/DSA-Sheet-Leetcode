class Solution {
public:
    vector<vector<int>> dp;
    int m,  n;
    vector<int> ith = {-1, 0, 0, +1};
    vector<int> jth = {0, -1, +1, 0};
    int func(vector<vector<int>> &matrix, int i, int j)
    {
        if(dp[i][j] != 0)   return dp[i][j];
        int mx = 1;
        for(int k=0;k<4;k++)
        {
            int a = i+ith[k];
            int b = j+jth[k];
            if(a>=0 && b>=0 && a<m && b<n && matrix[a][b] > matrix[i][j])
                mx = max(mx, 1+func(matrix, a, b));
        }
        dp[i][j] = mx;
        return mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        m = matrix.size();
        n = matrix[0].size();
        dp.assign(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans = max(ans, func(matrix,i,j));
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }    
        return ans;

    }
};
