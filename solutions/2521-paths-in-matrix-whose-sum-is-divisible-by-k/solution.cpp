class Solution {
public:
int cnt = 0, sum = 0;
int mod = 1000000007;
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int sum, int k)
    {
        if(i >= m || j >= n)    return;
        sum = (sum % mod + grid[i][j] % mod)%mod;
        if(i == m-1 && j == n-1)
        {
            if(sum % k == 0)
            {
                cnt++;
                return;
            }
        }
        dfs(grid, i+1, j, m, n, sum, k);
        dfs(grid, i, j+1, m, n, sum, k);
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        // dfs(grid, 0, 0, m, n, 0, k);
        // return cnt;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k] = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i == 0 && j == 0)    continue;
                for(int x = 0;x < k;x++)
                {
                    long long cnt = 0;
                    if(i > 0)   cnt += dp[i-1][j][x];
                    if(j > 0)   cnt += dp[i][j-1][x];
                    if(cnt == 0)    continue;
                    int curr_rem = (x + grid[i][j]) % k;
                    dp[i][j][curr_rem] = (dp[i][j][curr_rem] + cnt) % mod;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};
