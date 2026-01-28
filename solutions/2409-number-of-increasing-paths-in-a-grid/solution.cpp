class Solution {
public:
    vector<vector<int>> dp;
    int m, n;
    int mod = 1000000007;
    vector<int> ith = {-1, 0, 0, 1};
    vector<int> jth = {0, -1, 1, 0};
    int func(vector<vector<int>> &matrix, int i, int j)
    {
        if(dp[i][j] != 0)   return dp[i][j];
        int mx = 1;
        for(int k=0;k<4;k++)
        {
            int a = i+ith[k];
            int b = j+jth[k];
            if(a>=0 && b>=0 && a<m && b<n && matrix[a][b] > matrix[i][j])
                mx = mx % mod + func(matrix, a, b)%mod;
        }
        dp[i][j] = mx%mod;
        return mx%mod;
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                ans = (ans % mod + func(grid, i, j)%mod)%mod;
        }
        return ans % mod;
    }
};
