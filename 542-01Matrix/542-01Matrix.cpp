// Last updated: 2/9/2026, 1:28:03 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            pair<int, int> cell = q.front(); q.pop();
            int i = cell.first, j = cell.second;
            for(int k=0;k<4;k++)
            {
                int new_i = i + dir[k][0];
                int new_j = j + dir[k][1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && ans[new_i][new_j] == -1)
                {
                    ans[new_i][new_j] = ans[i][j]+ 1;
                    q.push({new_i,new_j});
                }
            }
        }
        return ans;
    }
};