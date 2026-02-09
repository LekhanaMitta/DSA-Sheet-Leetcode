// Last updated: 2/9/2026, 1:27:23 PM
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int cnt = 0,fresh=0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2) q.push({i,j}); 
                else if(grid[i][j] == 1)    fresh++;
            }
        }    
        while(!q.empty())
        {
            int sz = q.size();
            bool flag = false;
            for(int len = 0;len < sz;len++)
            {
                pair<int,int> cell = q.front();q.pop();
                for(int k=0;k<4;k++)
                {
                    int i = cell.first + dir[k][0];
                    int j = cell.second + dir[k][1];
                    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1)
                    {
                        flag = true;
                        fresh--;
                        grid[i][j] = 2;
                        q.push({i,j});
                    }
                }
            }
            if(flag) cnt++;
        }
        return (fresh == 0) ? cnt : -1;
    }
};