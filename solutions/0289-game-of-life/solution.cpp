class Solution {
public:
    int live_die(vector<vector<int>>&board, int i, int j)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return 0;
        if(board[i][j] == 1 || board[i][j] == 2)
            return 1;
        return 0;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt_live = 0;
                cnt_live += live_die(board, i+1, j);
                cnt_live += live_die(board, i+1, j+1);
                cnt_live += live_die(board, i+1, j-1);
                cnt_live += live_die(board, i, j+1);
                cnt_live += live_die(board, i, j-1);
                cnt_live += live_die(board, i-1, j);
                cnt_live += live_die(board, i-1, j-1);
                cnt_live += live_die(board, i-1, j+1);
                cout << i << " " << j << " " << cnt_live << endl;
                if(board[i][j])
                {
                    if(cnt_live < 2 || cnt_live > 3)    board[i][j] = 2;
                }
                else
                {
                    if(cnt_live == 3)   board[i][j] = 3;
                }
            }
            cout << endl;
        }
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == 2)    board[i][j] = 0;
                else if(board[i][j] == 3)   board[i][j] = 1;
            }
        }
    }
};
