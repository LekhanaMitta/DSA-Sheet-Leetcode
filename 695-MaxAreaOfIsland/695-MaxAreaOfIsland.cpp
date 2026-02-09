// Last updated: 2/9/2026, 1:27:47 PM
class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &grid, int &cnt)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i>n-1| i<0||j>m-1||j<0||grid[i][j]!=1) return 0;
        grid[i][j] =-1 ;
        cnt++;
        dfs(i+1, j, grid, cnt);
        dfs(i, j+1, grid, cnt);
        dfs(i-1, j, grid, cnt);
        dfs(i, j-1, grid, cnt);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    int cnt = 0;
                    cnt = dfs(i, j, grid, cnt);
                    mx = max(cnt, mx);
                }
            }
        }
        return mx;
    }
};